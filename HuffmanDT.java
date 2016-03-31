/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package huff;

import java.util.HashMap;
import java.util.PriorityQueue;

/**
 * Implement a simplified version of Huffman encoding on a string with
 * a given distribution for each character in it.  The chars are the
 * vowels of the latin alphabet.
 * @author thiebaut
 *
 */
public class HuffmanDT {
        static int IdCounter = 0;                               // used to number each node with unique Id
        
        /**
         * the node used to create the Huffman tree
         * @author thiebaut
         *
         */
        static class Node implements Comparable {
                public char letter;                             // the letter from the string, or '#' if inner node
                public int Id;                                  // unique Id (used to generate DOT graph)       
                public int freq;                                // counts number of occurrences
                public Node left;                               // pointer to left child, if any
                public Node right;                              // pointer to right child, if nay
                
                Node( char l, int f, Node lft, Node rt ) {
                        Id = IdCounter++;
                        letter = l; freq = f; left = lft; right = rt; 
                }
                /**
                 * returns whether node is a leaf.
                 * @return true if leaf, false otherwise.
                 */
                public boolean isLeaf() { return left==null && right==null; }
                @Override
                /**
                 * compareTo: needed because nodes will be kept in priority queue that
                 * keeps node with smallest freq value at the root. 
                 */
                public int compareTo(Object o) {
                        return freq - ((Node) o).freq;
                }
        }
        
        /**
         * retuns a synthetic string of characters (a, e, i, o, u) with a fixed distribution.
         * @return the string.
         */
        public static String getStringOfLetters() {
                String s = "";
               // RENE البيانات أو الحروف المختارة يتم إدخالها يدويا على الأقل حتى مقابلة الأستاذ //
                for ( int i=0; i<20; i++ ) s += "1 ";   // 20% of 1 رقم
                for ( int i=0; i<10; i++ )  s += "$ ";   // 10% of a رمز
                for ( int i=0; i<15; i++ )  s += "A";   // 15% of A حرف
                for ( int i=0; i<15; i++ )   s += "a";   // 15% of a حرف
                for ( int i=0; i<40; i++ )   s += "'";   // 40% of ' رمز
                                      //  خمس مدخلات //
                return s;
        }
        
        /**
         * computes the frequency associated with each letter found in the string s.
         * @param s the string containing the characters to encode.
         * @return a hashMap of the characters and their associated frequencies (as ints)
         */
        private static HashMap<Character, Integer> getLetterFrequencies( String s ) {
                HashMap<Character, Integer> freq = new HashMap<Character, Integer>();
                for ( int i=0; i< s.length(); i++ ) {
                        char c = s.charAt(i);
                        if ( freq.containsKey( c ) )
                                freq.put( c, freq.get( c )+1 );
                        else
                                freq.put( c,  1 );
                }
                return freq;
        }
        
        /**
         * buildHuffmanTree: builds a Huffman trie 
         * @param freqs the hashmap of frequencies associated with each char.
         * @return the root of the Huffman tree.
         */
        private static Node buildHuffmanTree( HashMap<Character, Integer> freqs ) {
                PriorityQueue<Node> prioQ = new PriorityQueue<Node>();
                for ( char c: freqs.keySet() ) 
                        prioQ.add( new Node( c, freqs.get(c), null, null ) );
                
                while ( prioQ.size() > 1 ) {
                        Node left = prioQ.poll();
                        Node right = prioQ.poll();
                        prioQ.add( new Node( '#', left.freq + right.freq, left, right ) );
                }
                
                return prioQ.poll();
        }

        /**
         * generates the DOT representation of the Hoffman tree
         * @param root
         */
        private static void generateHuffmanTreeDOT( Node root ) {

                System.out.println( "\ndigraph Huffman {" );
                DotDFS( root );
                System.out.println( "}\n" );
        }
        
        /**
         * recursive trunk of the DOT generation.
         * @param node
         */
        private static void DotDFS( Node node ) {
                if ( node.isLeaf() ) {
                        System.out.println(  String.format( "%d [label=\"%s (%d)\"];", 
                                        node.Id, node.letter, node.freq) );
                        return;
                }
                if ( node.left != null ) {
                        System.out.println(  String.format( "%d [label=\"%s (%d)\"];", 
                                        node.Id, node.letter, node.freq) );
                        System.out.println( String.format( "%d -> %d [label=\"0\"];", 
                                        node.Id, node.left.Id ) );
                        DotDFS( node.left );
                }
                if ( node.right != null ) {
                        System.out.println(  String.format( "%s [label=\"%s (%d)\"];", 
                                        node.Id, node.letter, node.freq) );
                        System.out.println( String.format( "%s -> %s [label=\"1\"];", 
                                        node.Id, node.right.Id ) );
                        DotDFS( node.right );
                }
        }

        /**
         * gets the string of 0s and 1s associated with each character.  Should normally
         * be a bit pattern, but is a String for the purpose of simplifying the code.
         * @param root
         * @return a hashMap of characters and their associated code.
         */
        private static HashMap<Character, String> getEncoding(Node root) {
                HashMap<Character, String> encoding = new HashMap<Character, String>();
                DFS( root, "", encoding );
                return encoding;
        }

        /**
         * Recursively performs a DFS to visit the Huffman trie and assign code to each
         * leaf. 
         * @param node
         * @param code
         * @param encoding
         */
        private static void DFS(Node node, String code, HashMap<Character, String> encoding) {
                if ( node.isLeaf() ) 
                        encoding.put( node.letter, code );
                else {
                        if ( node.left != null ) 
                                DFS( node.left, code+"0", encoding );
                        if ( node.right != null )
                                DFS( node.right, code+"1", encoding );
                }
        }

        /**
         * MAIN ENTRY POINT
         * @param args
         */
        public static void main(String[] args) {
                // create a synthetic string with know distribution of chars
                String s = getStringOfLetters();
                
                HashMap<Character, Integer> freqs = getLetterFrequencies( s );
                Node root = buildHuffmanTree( freqs );
                
                //generateHuffmanTreeDOT( root );
                
                HashMap<Character, String> encoding = getEncoding( root );
                System.out.println( encoding );
                
                int encodedStringLength = 0;
                int sumFreqs = 0;
                for ( char c: encoding.keySet() ) {
                        int freq = freqs.get( c );
                        sumFreqs += freq;
                        String code = encoding.get( c );
                        encodedStringLength += freq * code.length();
                }
                System.out.println( "Coding of ( 1 $ A a ' ) with 3 bits/char = " + sumFreqs * 3 + " bits" );
                System.out.println( "Huffman encoding of same chars   = " + encodedStringLength + " bits" );
                System.out.println( "Compression ratio                = " + sumFreqs * 3.0 / encodedStringLength );
        }



}