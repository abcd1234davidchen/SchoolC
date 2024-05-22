#include<iostream>
using namespace std;

typedef double* dptr;
class TwoD{
	public:
		TwoD():MaxRows(2),MaxCols(2){
			a= new double[2*2]();
		}
		TwoD (int rows, int cols):MaxRows(rows),MaxCols(cols){
			a= new double[rows*cols]();
		}
		TwoD(const TwoD& array0){
			MaxRows=array0.MaxRows;
			MaxCols=array0.MaxCols;
			a=new double[MaxRows*MaxCols]();
			copy(array0.a,array0.a+MaxRows*MaxCols,a);
		}
		void setValue(int i, int j, double value){
			a[i*MaxRows+j]=value;
		}
		double getValue(int rows, int cols){
			return a[rows*MaxRows+cols];
		}
		friend const TwoD operator+(const TwoD& arrayA, const TwoD& arrayB){
			TwoD temp(arrayA);
			for(int i=0;i<temp.MaxRows;i++){
				for(int j=0;j<temp.MaxCols;j++){
					temp.setValue(i,j,arrayA.a[i*temp.MaxRows+j]+arrayB.a[i*temp.MaxRows+j]);
				}
			}
			return temp;
		}
		TwoD& operator=(const TwoD& rvalue){
			if(this!=&rvalue){
				delete[] a;
				MaxRows=rvalue.MaxRows;
				MaxCols=rvalue.MaxCols;
				a=new double[rvalue.MaxRows*rvalue.MaxCols];
				copy(rvalue.a,rvalue.a+MaxRows*MaxCols,a);
			}
			return *this;		
		}
		
		~TwoD(){
			delete[] a;
		}
	private:
		int MaxRows, MaxCols;
		dptr a;
};

int main(){
	int row, col;
	double number;
	cout<<"Enter the number of rows: ";
	cin>>row;
	cout<<"\nEnter the number of columns: ";
	cin>>col;
	cout<< "\nInsert the values in first array\n";
	
	TwoD array1(row, col);
	for (int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<"enter the value in the"<<i<<"th row of "<<j<<"th column\n";
			cin>>number;
			array1.setValue(i,j, number);
		}
	}
	cout<<"the value in an two dimensional array "<<endl;
	for(int i = 0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<array1.getValue(i,j)<<" ";
		}
		cout<<endl;
	}
	cout << "Insert values in second array"<<endl;
	TwoD array2(row, col);
	for(int i=0;i<row;i++){
		for(int j= 0;j<col;j++){
			cout << "Enter the value in the "<<i<<"th row of " << j<<"th column\n";
			cin>>number;
			array2.setValue(i,j,number);
		}
	}
	cout<<"Addition of two arrays\n";
	TwoD array3(row, col);
	array3 = array1 + array2;
	cout << "The Result is: \n";
	for(int i=0;i<row;i++){
		for(int j= 0;j<col;j++){
			cout << array3.getValue(i,j) << " ";
		}
		cout<<endl;
	}
	return 0;
}