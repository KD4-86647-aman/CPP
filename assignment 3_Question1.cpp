#include <iostream>
using namespace std;

 class Volume{

    int length;
    int width;
    int height;

public:

    Volume():Volume(2,2,2){}
    Volume(int value):Volume(value,value,value){}

    Volume(int length, int width, int height)
    {
        this->length=length;
        this->width=width;
        this->height=height;
    }   

    void calculateVolume()
    {
        cout<<"Volume is : "<<length*width*height<<endl;
    }
 };

 int menu()
{
    int choice;
    cout<<"1. for Calculate with default values"<<endl;
    cout<<"2. for Calculate Volume with length,breadth and height with same value"<<endl;
    cout<<"3. for Calculate Volume with different length,breadth and height values."<<endl;
    cout<<"0. for To exit"<<endl;
    cin >> choice;
    return choice;
}

 int main()
 {
    
    int choice;
    while ((choice = menu()) != 0)
    {
          switch(choice)
    {
        case 1:
             {Volume v1;
             v1.calculateVolume();
             break;}
        case 2:
             {int a;
             cout<< "Enter the value"<< endl;
             cin>>a;
             Volume v2(a);
             v2.calculateVolume();
             break;}
        case 3:    
             {int a,b,c;
             cout<< "Enter length, width, hright"<<endl;
             cin>>a>>b>>c;
             Volume v3(a,b,c);
             v3.calculateVolume();} 
        default :
           
            break;    
        }
    }
    return 0;
    
 } 