#include <iostream>
using namespace std;

class Inspector;

class Number
{
    int value;

public:

    Number(int v)
    {
        value=v;
    }

    friend bool operator>(Number a,Number b);

    friend class Inspector;

    Number& operator++()
    {
        ++value;
        return *this;
    }

    Number operator++(int)
    {
        Number temp=*this;
        value++;
        return temp;
    }

    Number& operator=(Number n)
    {
        value=n.value;
        return *this;
    }

    void display()
    {
        cout<<"Value: "<<value<<endl;
    }
};

bool operator>(Number a,Number b)
{
    return a.value>b.value;
}

class Inspector
{
public:
    void show(Number n)
    {
        cout<<"Inspector sees value: "<<n.value<<endl;
    }
};

int main()
{
    Number n1(10),n2(20);

    ++n1;
    n2++;

    n1.display();
    n2.display();

    Inspector i;
    i.show(n1);

    if(n1>n2)
        cout<<"n1 greater"<<endl;
    else
        cout<<"n2 greater"<<endl;

    return 0;
}
