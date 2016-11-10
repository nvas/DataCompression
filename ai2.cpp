
#include <fstream>
#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
class Table{

public:
   
    Table(){
     
    };
    
    
    fstream getFile(string file_name);
    vector<vector<double>> DataVectorFromFile(fstream& fileName);
    vector<vector<double>> MainVector;
    
  
    
    
  /**/  void print2DVecotr();//Populate the table with the data from a CSV file.
    
 /**/   double getAverage_column(int col);//Get the average of a column specified by the user
    
    double getSampleStdDevOfColumn(int col);//Get the corrected sample standard deviation of a column specified by the user.
    
 /**/   int getNumberOfRows();//Get the number of rows in the table
    
 /**/   int getNumerOfColumns();//Get the number of columns in the table.
    
    double getCell(vector<vector<double>> MainVector) ;
    
    void changeCell(vector<vector<double>> &vector);
    
    void methodStdTable(){}             //Call a method that standardises the data in the table
    
    void removeRow(vector<vector<double>> vector);//Remove a specific row from the table.
    
    void removeColumn(vector<vector<double>> vector);//Remove a specific column from the table.
    
    
        
    
//Add a row containing numbers to the table.
    //void addRow(vector<vector<double>> vector){vector<double> d;}
    void addRow(vector<vector<double>> vecto);//Add a column containing numbers to the table.
    void addColumn(vector<vector<double>> vecto);
    //ofstream operator<<(fstream obj){return obj;}    //Add a column containing numbers to the table.
    

};



int main()
{
 
    Table table_;    //Creating table object
    
    
    fstream f=table_.getFile("Data.csv");      //    fstream object assign table_ object to call getfile(string file) from Table class
    
    table_.DataVectorFromFile(f);
    table_.print2DVecotr();
    table_.getAverage_column(1);
    table_.getNumberOfRows();
    table_.getNumerOfColumns();
    table_.getSampleStdDevOfColumn(2);
    //table_.getCell(DataTable);
    //table_.changeCell(DataTable);
    //table_.print2DVecotr(DataTable);
    //table_.removeRow(DataTable);
   
    //table_.removeColumn(DataTable);
    //table_.removeRow(DataTable);
    // table_.addColumn(DataTable);
    //table_.addRow(DataTable);
    //table_.print2DVecotr(DataTable);

  //  cout<<table_;
    
    return 0;
    
    
    
    
    
    
    
}
/*******************************************************************************************/
fstream Table::getFile(string file_name){
    
    
    
        fstream file_name_(file_name);
    
    
    return file_name_;
    
    
}
    

/*******************************************************************************************/

vector<vector<double>> Table::DataVectorFromFile(fstream& fileName){
    
         vector<double> dim_ ;
         string item;


    double val;
    for (string line; getline(fileName, line); )
    {
        
        stringstream l(line);
        
        while (getline(l, item, ','))
            {
                val = atof(item.c_str());
                
                dim_.push_back(val);
                
                
                
            }
        
        
        MainVector.push_back(dim_);
        dim_.clear();
       
        
        
  
        
    }
    


    return MainVector;
}

/*******************************************************************************************/

double Table:: getAverage_column(int col){
    double avg=0.0,total = 0.0,col_no;int i;
    
    
    col_no-=col-1;
    
    for(  i=0; i<MainVector.size(); i++) {
        
            total=total +MainVector[i][col_no];
        
        }
    avg=total/36;
    
   // cout<<"Number of rows is : "<<i<<endl;
    cout<<"Total sum is equal to : "<<total<<endl;
    cout<<"Average is equal to : "<<avg<<endl;
        return avg;
    
}
/*******************************************************************************************/

double Table:: getSampleStdDevOfColumn(int col){
    double average=0.0,sum_of_pow_variants=0.0;
    double InverseN;
    double StdDev;
    int spcicol=col-1;
     average=Table::getAverage_column(spcicol);
    
    for(int row=0;row<MainVector.size();row++)
    {
     
          sum_of_pow_variants += pow((MainVector[row][spcicol])-average, 2);
       
    }
    InverseN = 1.00/(MainVector.size()-1);
    StdDev=sqrt(InverseN * sum_of_pow_variants);
    cout<<"Std is : "<<StdDev<<endl;
    return StdDev;

}

/*******************************************************************************************/

int Table::getNumberOfRows(){
    cout<<"NumberOfRows : "<<MainVector.size()<<endl;
    return (int)MainVector.size();
}
/*
 for(  i=0; i<vector.size(); i++) {
 
 total=total +vector[i][col_no];
 
 }
 */
/*******************************************************************************************/

int Table::getNumerOfColumns(){
    int j=0;

    for (  ;j<MainVector[0].size();j++){
        // double res = vector[i][j]+vector[i][j];
    
        
}
    cout<<"Number of Columns is :"<<j<<endl;
    
    return j;
}
/*******************************************************************************************/
void Table:: print2DVecotr(){
    int j=0;
  
  
   // for(vector<vector <double>>::iterator item=vector.begin();item!vector.end();item++){}
        cout<<"entered "<<MainVector.size()<< " row"<<endl;
    int counter=0;
       for(int i=0;i<MainVector.size();i++){
           
           for (  j=0;j<MainVector[i].size();j++){
            // double res = vector[i][j]+vector[i][j];
                counter++;
               cout<<setw(12)<<MainVector[i][j];
           }
        
           cout<<endl;
    }
 
  //  *NumberOfColumns_ptr=num_cols;
    cout<<"total number of cells is : "<<counter<<endl;
 
   // cout<<"total number of columns is : "<<*NumberOfColumns_ptr<<endl;
    
}

/*******************************************************************************************/

void Table:: removeRow(vector<vector<double>> vector){
    
int rowno;
    cout<<"Enter row index you want to delete"<<endl;
    cin>>rowno;
    rowno-=1;
    if (rowno < vector.size() )
    {
        vector.erase( vector.begin() + rowno );
    }
    
    Table::print2DVecotr();

    
}

/*******************************************************************************************/
void Table:: removeColumn(vector<vector<double>> vector){
    
    int colno;
    cout<<"Enter col index you want to delete"<<endl;
    cin>>colno;
    if(colno<=vector[0].size())
    {
        colno=colno-1;
        for(int i=0;i< vector.size();i++)
        {vector[i].erase(vector[i].begin() + colno);}
       
    }
    Table::print2DVecotr();
}






/*******************************************************************************************/
double Table:: getCell(vector<vector<double>> vector){
    int x,y;
    double cell;
    cout<<"Enter x"<<endl;
    cin>>x;
    cout<<"Enter y"<<endl;
    cin>>y;
    x=x-1;y=y-1;
    cout<<"The current value of (x,y) is : "<<vector[x][y]<<endl;
    
    return cell;
    

}

/*******************************************************************************************/


void Table:: changeCell(vector<vector<double>> &vector){
    int x,y,row,col;

    double newValuetoCell;
    cout<<"Enter cell row number "<<endl;
    cin>>x;
    cout<<"Enter cell col number "<<endl;
    cin>>y;
    cout<<"Enter the new value "<<endl;
    cin>>newValuetoCell;
    cout<<"changed cell : "<<newValuetoCell<<endl;
        row=x-1;
        col=y-1;
        if(col<=vector[0].size()&&row<=vector.size())
            vector[row][col]=newValuetoCell;
        else cout<<"review your x,y"<<endl;
        cout<<endl;
        cout<<"changed cell : "<<newValuetoCell<<endl;
        cout<<"changed cell to : "<<vector[row][col]<<endl;

    
}

/*******************************************************************************************/

void Table:: addRow(vector<vector<double>> vecto){
    double num;
    vector<double> k;
    
    do {
     
        cout<<"Enter a number: "<<endl;
        cin>>num;
     
            k.push_back(num);
        

    }while (k.size()< vecto[0].size());
    vecto.push_back(k);
    Table::print2DVecotr();
}

/*******************************************************************************************/


void Table:: addColumn(vector<vector<double>> vecto){
    double num;
    int i=0;
    vector<double> k;
    cout<<"Enter col val no "<<i<<endl;
    do{cout<<"Enter col val no "<<i<<endl;
    cin>>num;
        
        k.push_back(num);
     
        i++;
    }while(i<=vecto.size());
    for(int col=0;col<vecto.size();col++)
    {
        
        vecto[col].push_back(k[col]);
    }
    Table::print2DVecotr();
    cout<<"vecto "<<vecto.size()<<endl;
    cout<<"k "<<k.size()<<endl;

}

