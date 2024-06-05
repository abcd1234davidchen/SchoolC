#ifndef TWOD_H
#define TWOD_H

#include<iostream>
using namespace std;

class TwoD{
    private:
        int** arr;
        int row;
        int column;
    public:
        TwoD();
        TwoD(int r,int c);
        TwoD(const TwoD& other);
        ~TwoD();
        int getColumn()const;
        int getRow()const;
        void setRow(int newRow);
        void setColumn(int newColumn);
        int getValue(int r,int c)const;
        void setValue(int r,int c,int value);
        TwoD& operator=(const TwoD& other);
        const TwoD operator+(const TwoD& other)const;
        const TwoD operator*(const TwoD& other)const;
        friend ostream& operator<<(ostream& out,const TwoD& theOne){
            for(int i=0;i<theOne.getRow();i++){
                for(int j=0;j<theOne.getColumn();j++){
                    out<<theOne.getValue(i,j)<<" ";
                }
                out<<endl;
            }
            return out;
        };

};

#endif
