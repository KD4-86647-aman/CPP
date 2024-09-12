#include<iostream>
using namespace std;

class address
{
private:
        string building;
        string street;
        string city;
        int pin;
public:
address()
{
  cout<<"Inside Constructor"<<endl;
  building="";
  street= "";
  city = "";
  pin = 00;
}
  ~address() 
{   
  cout << "Inside Destructor" <<endl;
}
  
  void setaddress() // setter
        {
            cout << "Inside Setter" <<endl;
            building= "Antilia";
            street="Wall street";
            city = "mumbai";
            pin = 400927;
        }

    void getaddress() const // getter
        {
            cout << "Inside Getter"<<endl;
            cout << building<< endl;
            cout << street<< ","<<endl;
            cout << city <<","<< pin<<endl;        
        }

    void accept(){
            cout<<"Add address = "<<endl;
            cout<<"Enter building_name -";
            getline(cin,building);
            cout<<"Enter street -" ;
            getline(cin,street);
            cout<<"Enter city -" ; 
            getline(cin,city);
            cout<<"Enter Pin -" ;
            cin>>pin;
    }
   void display(){

    cout <<"Address Details"<< endl;
    cout <<building<< endl;
    cout << street<< ","<<endl;
    cout << city <<","<< pin<<endl;
   }
};

int main()
{
    address a1;
    a1.getaddress();
    a1.setaddress();
    a1.getaddress();
    a1.accept();
    a1.display();
    cout<<"_______"<<endl;
    address a2;
    a2.getaddress();
    a2.setaddress();
    a2.getaddress();
    a2.accept();
    a2.display();
     
    return 0;
}