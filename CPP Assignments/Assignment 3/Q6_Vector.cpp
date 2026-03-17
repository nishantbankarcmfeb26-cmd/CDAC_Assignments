#include <iostream>
using namespace std;

class Vector
{
    int *arr;
    int size;

public:

    Vector(int s)
    {
        size=s;
        arr=new int[size];

        for(int i=0;i<size;i++)
            arr[i]=0;
    }

    int& operator[](int index)
    {
        return arr[index];
    }

    int operator()()
    {
        int sum=0;

        for(int i=0;i<size;i++)
            sum+=arr[i];

        return sum;
    }

    ~Vector()
    {
        delete[] arr;
    }
};

int main()
{
    Vector v(5);

    v[2]=50;
    v[0]=10;
    v[1]=20;

    cout<<"Sum = "<<v()<<endl;

    return 0;
}
