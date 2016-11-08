
#include <fstream>
#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Table{

public:
    int NumberOfRows;
    int *NumberOfRows_ptr=&NumberOfRows;
    int NumberOfColumns;
    int *NumberOfColumns_ptr=&NumberOfColumns;
    Table(){};
  //  string mfileName;
  //  vector<vector<double>> __dim;
    vector<vector<double>> MainVector;
    
    
    fstream getFile();
    vector<vector<double>> DataVectorFromFile(fstream& fileName);
    
  /**/  void print2DVecotr(vector<vector<double>> vector);//Populate the table with the data from a CSV file.
    
 /**/   double getAverage_column(vector<vector<double>> vector);//Get the average of a column specified by the user
    
    double getSampleStdDevOfColumn(int row,int col){double StdDev;return StdDev;}//Get the corrected sample standard deviation of a column specified by the user.
    
 /**/   int getNumberOfRows(vector<vector<double>> vector);//Get the number of rows in the table
    
 /**/   int getNumerOfColumns();//Get the number of columns in the table.
    
    double getCell(vector<vector<double>> MainVector) ;
    
    void changeCell(vector<vector<double>> vector);
    
    void methodStdTable(){}             //Call a method that standardises the data in the table
    
    void removeRow(vector<vector<double>> &temp_remove);//Remove a specific row from the table.
    
    void removeColumn(){}//Remove a specific column from the table.
    
    void addRow(){}//Add a row containing numbers to the table.
    
    void addColumn(){}//Add a column containing numbers to the table.
    
    //ofstream operator<<(fstream obj){return obj;}    //Add a column containing numbers to the table.
    
};





int main()
{
 
    Table table_;    //Creating table object
    
    
    fstream f=table_.getFile();      //    fstream object assign table_ object to call getfile(string file) from Table class
    
    vector<vector<double>> DataTable = table_.DataVectorFromFile(f);
    table_.print2DVecotr(DataTable);
    //table_.removeRow(DataTable);
    
    table_.getAverage_column(DataTable);
    table_.getNumberOfRows(DataTable);
    table_.getNumerOfColumns();
    table_.getCell(DataTable);
    table_.changeCell(DataTable);
    table_.print2DVecotr(DataTable);


    return 0;
    
    
    
    
    
    
    
}
/*******************************************************************************************/
fstream Table::getFile(){
        string file_name;
        cout<<"Insert File Name with extension\n";
        getline(cin,file_name);
    
        fstream file_name_(file_name);
    
    
    return file_name_;
    
    
}
    

/*******************************************************************************************/

vector<vector<double>> Table::DataVectorFromFile(fstream& fileName){
         vector<vector<double>> __dim_;
         vector<double> _dim_ ;
         string item;
         int row=0;
    //cout<<"File has been  read as a vector of two dimensions"<<endl;

    double val;
    for (string line; getline(fileName, line); )
    {
         row++;
        stringstream l(line);
        
        while (getline(l, item, ','))
            {
                val = atof(item.c_str());
                
                _dim_.push_back(val);
                
                
            }
        
        
        __dim_.push_back(_dim_);
       
        
        _dim_.clear();
        
        __dim_.resize(row);
       // cout<<row<<endl;
        
    }
    
  //  MainVector=__dim_;

    return __dim_;
}

/*******************************************************************************************/

double Table:: getAverage_column(vector<vector<double>> vector){
    double avg=0.0,total = 0.0,col_no;int i;
    
    cout<<"Enter number of column you want its average"<<endl;
    cin>>col_no;
    
    for(  i=0; i<vector.size(); i++) {
        
            total=total +vector[i][col_no];
        
        }
    avg=total/36;
    
    cout<<"Number of rows is : "<<i<<endl;
    cout<<"Total sum is equal to : "<<total<<endl;
    cout<<"Average is equal to : "<<avg<<endl;
        return avg;
    
}
/*******************************************************************************************/

int Table::getNumberOfRows(vector<vector<double>> vector){
    cout<<"NumberOfRows : "<<MainVector.size()<<endl;
    return (int)MainVector.size();
}
/*
 for(  i=0; i<vector.size(); i++) {
 
 total=total +vector[i][col_no];
 
 }
 */
/*******************************************************************************************/

int Table::getNumerOfColumns(){cout<<"NumberOfColumns"<<NumberOfColumns<<endl;return NumberOfColumns;}
/*
for(int i=0;i<vector.size();i++){
    
    for (  j=0;j<vector[i].size();j++){
        // double res = vector[i][j]+vector[i][j];
        counter++;
        cout<<setw(12)<<vector[i][j];
        }
        
        cout<<endl;
        }
*/
/*******************************************************************************************/
void Table:: print2DVecotr(vector<vector<double>> vector){
    int j=0;
    int num_cols;
  
   // for(vector<vector <double>>::iterator item=vector.begin();item!vector.end();item++){}
        cout<<"entered "<<vector.size()<< " row"<<endl;
    int counter=0;
       for(int i=0;i<vector.size();i++){
           
           for (  j=0;j<vector[i].size();j++){
            // double res = vector[i][j]+vector[i][j];
                counter++;
               cout<<setw(12)<<vector[i][j];
           }
        
           cout<<endl;
    }
    num_cols=j;
    *NumberOfColumns_ptr=num_cols;
    cout<<"total number of cells is : "<<counter<<endl;
    cout<<"total number of columns is : "<<j<<endl;
    cout<<"total number of columns is : "<<*NumberOfColumns_ptr<<endl;
    
}

/*******************************************************************************************/

void Table:: removeRow(vector<vector<double>> &temp_remove){
    
int index;
    cout<<"Enter row index you want to delete"<<endl;
    cin>>index;
    temp_remove.erase(temp_remove.begin()+(index-1));

   
    
}

/*******************************************************************************************/


double Table:: getCell(vector<vector<double>> vector){
    int x,y;
    double cell;
    cout<<"Enter x"<<endl;
    cin>>x;
    cout<<"Enter y"<<endl;
    cin>>y;
    cout<<"The current value of (x,y) is : "<<vector[x-1][y-1]<<endl;
    
    return cell;
    

}

/*******************************************************************************************/


void Table:: changeCell(vector<vector<double>> vector){
    int x,y,row,col;
    row=x;col=y;
    double newValuetoCell;
    cout<<"Enter cell row number "<<endl;
    cin>>x;
    cout<<"Enter cell col number "<<endl;
    cin>>y;
    cout<<"Enter the new value "<<endl;
    cin>>newValuetoCell;
    cout<<"changed cell : "<<newValuetoCell<<endl;
 
    if(row<=vector.size() && col<=vector[row].size()){
        row=row-1;
        col=col-1;
        vector[row][col]=newValuetoCell;
         cout<<"changed cell : "<<newValuetoCell<<endl;
        cout<<"changed cell to : "<<vector[row][col]<<endl;
    }
    
}
