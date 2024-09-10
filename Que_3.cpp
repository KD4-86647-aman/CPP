#include<iostream>
using namespace std;

namespace NStudent
{
    class Student
{
    int roll_no;
    string name;
    int marks;
    public:

        void initStudent()
        {
            roll_no = 0;
            name = "Rushi";
            marks = 0;

            cout<<"The Default Student data  :"<<endl;
            cout<<"Roll No:" <<roll_no<<"      "<<"Student Name:"<<name<<"      "<<"Students Marks:"<<marks<<endl;
        }

        void acceptStudentFromConsole()
        {

            cout<<"Enter the Roll no :"<<endl;
            cin>>roll_no;

            cout<<"Enter the Student Name: "<<endl;
            cin>>name;

            cout<<"Enter the Marks: "<<endl;
            cin>>marks;

            
        }

        void printStudentOnConsole()
        {
            cout<<"The Students details are :"<<endl;
            cout<<roll_no<<"|---|"<<name<<"|---|"<<marks<<endl;

        }
   
        int menu()
        {
            int choice = 0;

           //cout<<"Please Enter your Choice"<<endl;
            cout<<"---------------Student Details------------------"<<endl;
            cout<<"1\t"<<" Add-Student Details : "<<endl; 

            cout<<"2\t"<<" Display-Students Details :"<<endl;

            cout<<"3\t"<<" Sample Student detail : "<<endl;



            cout<<"0\t"<<"-----------EXIT------------- "<<endl;

            cout<<"Please Enter your Choice: "<<endl;

            
            cin>>choice;
            return choice;
        }

};

}

using namespace NStudent;

int main()
{
    Student sobj;

    
    
    int ians = 0;
    
    while ((ians = sobj.menu())!= 0)
    {
        switch (ians)
        {
            case 1:
            sobj.acceptStudentFromConsole();
            break;

            case 2:
            sobj.printStudentOnConsole();
            break;


            case 3:
            sobj.initStudent();
            break;


            default:
            cout<<"Invalid Choice:\n";
            break;

        }
    }


    
    return 0;
}
