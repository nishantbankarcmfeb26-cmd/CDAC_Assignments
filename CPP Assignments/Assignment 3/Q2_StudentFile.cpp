#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    int marks;

    Student(){}
    
    Student(int r,string n,int m)
    {
        roll=r;
        name=n;
        marks=m;
    }

    ~Student()
    {
        cout<<"Destroying student "<<name<<endl;
    }
};

int main()
{
    Student s[3] = {
        Student(1,"Amit",80),
        Student(2,"Rahul",85),
        Student(3,"Priya",90)
    };

    ofstream fout("students.txt");

    for(int i=0;i<3;i++)
    {
        fout<<s[i].roll<<" "<<s[i].name<<" "<<s[i].marks<<endl;
    }

    fout.close();

    ifstream fin("students.txt");

    int r,m;
    string n;

    cout<<"File contents:"<<endl;

    while(fin>>r>>n>>m)
    {
        cout<<r<<" "<<n<<" "<<m<<endl;
    }

    fin.close();

    return 0;
}
