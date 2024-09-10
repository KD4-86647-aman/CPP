#include<iostream>
using namespace std;

struct DateTime
{
   
        int date;
        int month;
        int year;
        

        void initDate()
        {
            date = 1;
            month = 1;
            year = 1900;

            cout<<"Default Date is :"<<date<<"/"<<month<<"/"<<year<<endl;


        }
   

        void acceptDateOnConsole()
        {
            cout<<"Enter Date:"<<endl;
            cin>>date;           

            cout<<"Enter Month:"<<endl;
            cin>>month;

            cout<<"Enter Year:"<<endl;
            cin>>year;
        }


        void printDateOnConsole()
        {
            cout<<"The Date : ";
            cout<<date<<"/"<<month<<"/"<<year<<endl;
        } 

        bool isLeapYear()
        {
            if(year % 4 ==0)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        int menu()
        {
            int choice = 0;

           //cout<<"Please Enter your Choice"<<endl;
            
            cout<<"1\t"<<" Add-Date : "<<endl; 

            cout<<"2\t"<<" Display-Date :"<<endl;

            cout<<"3\t"<<" Check Leap Year :"<<endl;

            cout<<"4\t"<<" Default Date : "<<endl;



            cout<<"0\t"<<"EXIT "<<endl;

            cout<<"Please Enter your Choice: "<<endl;

            
            cin>>choice;
            return choice;
        }

};

int main()
{
    struct DateTime obj1;
    
    int ians = 0;
    
    while ((ians = obj1.menu())!= 0)
    {
        switch (ians)
        {
            case 1:
            obj1.acceptDateOnConsole();
            break;

            case 2:
            obj1.printDateOnConsole();
            break;


            case 3:
            if(obj1.isLeapYear())
            cout<<obj1.year <<": is Leap Year:\n";
            else
            {
                cout<<obj1.year <<": is not Leap Year \n";

            }
            break;

            case 4:
            obj1.initDate();
            break;


            default:
            cout<<"Invalid Choice:\n";
            break;

        }
    }


    
    return 0;
}