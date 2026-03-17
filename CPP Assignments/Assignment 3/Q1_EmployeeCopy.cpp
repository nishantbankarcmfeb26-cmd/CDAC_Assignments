#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    mutable int accessCount;

    Employee(int i,string n)
    {
        id=i;
        name=n;
        accessCount=0;
    }

    Employee(const Employee &e)
    {
        id=e.id;
        name=e.name;
        accessCount=e.accessCount;
        cout<<"Copy constructor called"<<endl;
    }

    const void display() const
    {
        accessCount++;
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Access Count: "<<accessCount<<endl;
        cout<<endl;
    }
};

int main()
{
    Employee e1(1,"Nishant");

    e1.display();
    e1.display();
    e1.display();

    Employee e2 = e1;

    cout<<"Copied object:"<<endl;
    e2.display();

    return 0;
}
