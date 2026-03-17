#include <iostream>
using namespace std;

class Matrix
{
    int **a;
    int rows,cols;

public:

    Matrix(int r,int c)
    {
        rows=r;
        cols=c;

        a=new int*[rows];

        for(int i=0;i<rows;i++)
            a[i]=new int[cols];
    }

    friend istream& operator>>(istream &in,Matrix &m)
    {
        for(int i=0;i<m.rows;i++)
            for(int j=0;j<m.cols;j++)
                in>>m.a[i][j];

        return in;
    }

    friend ostream& operator<<(ostream &out,Matrix &m)
    {
        for(int i=0;i<m.rows;i++)
        {
            for(int j=0;j<m.cols;j++)
                out<<m.a[i][j]<<" ";
            out<<endl;
        }

        return out;
    }

    Matrix operator+(Matrix &m)
    {
        Matrix temp(rows,cols);

        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                temp.a[i][j]=a[i][j]+m.a[i][j];

        return temp;
    }

    bool operator==(Matrix &m)
    {
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(a[i][j]!=m.a[i][j])
                    return false;

        return true;
    }

    ~Matrix()
    {
        for(int i=0;i<rows;i++)
            delete[] a[i];

        delete[] a;
    }
};

int main()
{
    Matrix m1(2,2),m2(2,2);

    cout<<"Enter Matrix 1"<<endl;
    cin>>m1;

    cout<<"Enter Matrix 2"<<endl;
    cin>>m2;

    Matrix m3 = m1 + m2;

    cout<<"Sum:"<<endl;
    cout<<m3;

    if(m1==m2)
        cout<<"Matrices are equal"<<endl;
    else
        cout<<"Matrices are not equal"<<endl;

    return 0;
}
