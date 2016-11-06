#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int k;
    vector<vector<double> > values;
    vector<double> valueline;
    ifstream fin("Data.csv");
    string item;
    for (string line; getline(fin, line); )
    {
        istringstream in(line);
        
        while (getline(in, item, ','))
        {
            valueline.push_back(atof(item.c_str()));
          
        }
        
        values.push_back(valueline);
       
        valueline.clear();
    }
  
    for(int i=0;i<values.size();i++){
    
        for (int j=0;j<values[i].size();j++){
           // double res = values[i][j]+values[i][j];
           
            cout<<setw(12)<<values[i][j];
        }
            cout<<"\n";
    }
    
}
