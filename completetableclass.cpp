#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
class Table{
public:
    Table(){};
    fstream getFile(string file_name);//To get any CSVfile WITH "," delimeter in the system
    vector<vector<double>> DataVectorFromFile(fstream& fileName);//To get file data into vector
    vector<vector<double>> MainVector;//Represent The main vector in the class
    /**/ void print2DVecotr();//1.Populate the table with the data from a CSV file.
    /**/ double getAverage_column(int col);//2.Get the average of a column specified by the user
    /**/ double getSampleStdDevOfColumn(int col);//3.Get the corrected sample standard deviation of a column specified by the user.
    /**/ int getNumberOfRows();//4.Get the number of rows in the table
    /**/ int getNumerOfColumns();//5.Get the number of columns in the table.
    /**/ double getCell() ;//6.Get the value of a specific cell in the table.
    void changeCell(int x_row,int y_col,double newValuetoCell);//7.Change the value of a specific cell in the table.
    void methodStdTable();            //8.Call a method that standardises the data in the table
    void removeRow();//9.Remove a specific row from the table.
    void removeColumn();//10.Remove a specific column from the table.
    void addRow();//11.Add a column containing numbers to the table.
    void addColumn();//12.Add a column containing numbers to the table.
    friend ostream &operator<<(ostream &stream, Table &obj);//13.Add a column containing numbers to the table
};
int main()
{
    Table table_;    //Creating table object
    fstream f=table_.getFile("Data.csv");      //    fstream object assign table_ object to call getfile(string file) from Table class
    table_.DataVectorFromFile(f);
    table_.print2DVecotr();
    table_.getAverage_column(1);
    table_.getSampleStdDevOfColumn(2);
    table_.getNumberOfRows();
    table_.getNumerOfColumns();
    table_.getCell();
    table_.changeCell(1,1,6);
    table_.methodStdTable();
    cout<<table_;
    table_.print2DVecotr();
    table_.removeRow();
    table_.removeColumn();
    table_.addRow();
    table_.addColumn();
    
    return 0;
}
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
             //
    }
    return MainVector;
}
/*1.Populate the table with the data from a CSV file.*/
void Table:: print2DVecotr(){
    int row,column = 0;
    cout<<"Total number of Rows using .size() function is ==> "<<MainVector.size()<<endl;
    int cells=0;
    for( row=0;row<MainVector.size();row++){
        cout<<"Row No"<<row+1;
        for ( column=0 ;column<MainVector[row].size();column++){
            cells++;
            cout<<setw(12)<<MainVector[row][column];
        }
        cout<<endl;
    }
}
/*2.Get the average of a column specified by the user*/
double Table:: getAverage_column(int colno){
    double avg=0.0,total = 0.0,col_no;int i;
    col_no-=colno-1;
    for(  i=0; i<MainVector.size(); i++) {
        total=total +MainVector[i][col_no];
    }
    avg=total/MainVector.size();
//    cout<<"Average of column no ("<<col<< ") is equal to : "<<avg<<endl;
    return avg;
}
/*3.Get the corrected sample standard deviation of a column specified by the user.*/
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
  //  cout<<"Standars Deviation of column No ("<<col<<") is : "<<StdDev<<endl;
    return StdDev;
}
/*4.Get the number of rows in the table*/
int Table::getNumberOfRows(){
    cout<<"NumberOfRows : "<<MainVector.size()<<endl;
    return (int)MainVector.size();
}
/*Get the number of columns in the table.*/
int Table::getNumerOfColumns(){
    int j=0;
    for (  ;j<MainVector[0].size();j++){}
    cout<<"Number of Columns is :"<<j<<endl;
    return j;
}
/*6.Get the value of a specific cell in the table.*/
double Table:: getCell(){
    int x,y;double cell;
    cout<<"Enter x"<<endl;
    cin>>x;
    cout<<"Enter y"<<endl;
    cin>>y;
    x=x-1;y=y-1;
    cout<<"The current value of (x,y) is : "<<MainVector[x][y]<<endl;
    return cell;
}
/*7.Change the value of a specific cell in the table.*/
void Table:: changeCell(int x_row,int y_col,double newValuetoCell){
    int x=x_row,y=y_col,row,col;
    double newVal=newValuetoCell;
    row=x-1;
    col=y-1;
    if(col<=MainVector[0].size()&&row<=MainVector.size())
        MainVector[row][col]=newValuetoCell;
    else cout<<"review your x,y"<<endl;
    cout<<endl;
    cout<<"your new value ==>  "<<newVal<<endl;
    cout<<"data in "<<"("<<x<<","<<y<<")"<<" has been changed to ==>"<<MainVector[row][col]<<endl;
}
/*8.Call a method that standardises the data in the table*/
void Table:: methodStdTable(){
    vector<vector<double>> standardised_vector;
    double standardised_cell,total=0,avg=0;int col=0,row=0;
    standardised_vector.resize(MainVector.size());
        for( row=0;row<MainVector.size();row++)
        {
            for( col=0;col<MainVector[row].size();col++)
                {
            
                    total = total + MainVector[row][col];
                    avg=total/MainVector.size();
                    standardised_cell = 1/pow(MainVector[row][col]-avg, 2);
                    standardised_vector[row].push_back(standardised_cell);
           
            
                }
            
        }
  
           MainVector = standardised_vector;
    cout<<"Standardised Data ==> "<<endl;
}
/*9.Remove a specific row from the table.*/
void Table:: removeRow(){
    int rowno;
    cout<<"Enter row index you want to delete"<<endl;
    cin>>rowno;
    rowno-=1;
    if (rowno < MainVector.size() )
    {
        MainVector.erase( MainVector.begin() + rowno );
    }
    Table::print2DVecotr();
}
/*10.Remove a specific column from the table.*/
void Table:: removeColumn(){
    int colno;
    cout<<"Enter col index you want to delete"<<endl;
    cin>>colno;
    if(colno<=MainVector[0].size())
    {
        colno=colno-1;
        for(int i=0;i< MainVector.size();i++)
        {MainVector[i].erase(MainVector[i].begin() + colno);}
    }
    Table::print2DVecotr();
}
/*11.Add a column containing numbers to the table.*/
void Table:: addRow(){
    double num;
    vector<double> new_row;
    do {
        cout<<"Enter a number: "<<endl;
        cin>>num;
        new_row.push_back(num);
    }while (new_row.size()< MainVector[0].size());
    MainVector.push_back(new_row);
    Table::print2DVecotr();
}
/*12.Add a column containing numbers to the table.*/
void Table:: addColumn(){
    double num;
    int i=0;
    vector<double> new_col;
    cout<<"Enter col val no "<<i<<endl;
    do{cout<<"Enter col val no "<<i<<endl;
        cin>>num;
        new_col.push_back(num);
        i++;
    }while(i<=MainVector.size());
    for(int col=0;col<MainVector.size();col++)
    {
        MainVector[col].push_back(new_col[col]);
    }
    Table::print2DVecotr();
    cout<<"vecto "<<MainVector.size()<<endl;
    cout<<"k "<<new_col.size()<<endl;
}
/*13.Add a column containing numbers to the table.*/
ostream  &operator<<(ostream &stream, Table &obj){
    obj.print2DVecotr();
    /*cout<<"Total number of Rows using .size() function is ==> "<<obj.MainVector.size()<<endl;
    int cells=0;
     for( int row=0;row<obj.MainVector.size();row++){
            for ( int column=0 ;column<obj.MainVector[row].size();column++){
                cells++;
                stream <<setw(12)<<obj.MainVector[row][column];
            }
           stream<<endl;
     }*/
    return stream;	
}
