#include <iostream>
using namespace std;

class DivideByZero{};

int divide(int a,int b) throw(DivideByZero)
{
    if(b==0)
        throw DivideByZero();

    return a/b;
}

int main()
{
    int x=10,y=0;

    try
    {
        try
        {
            int result = divide(x,y);
            cout<<result<<endl;
        }
        catch(DivideByZero)
        {
            cout<<"Inside inner catch"<<endl;
            throw;
        }
    }
    catch(DivideByZero)
    {
        cout<<"Handled in outer catch"<<endl;
    }

    return 0;
}
