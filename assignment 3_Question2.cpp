#include <iostream>
using namespace std ;
class Tollbooth{
private:
    unsigned int carCount;    
    double cashTotal;        
    unsigned int payingCarCount; 
    unsigned int noPayCarCount; 

public:
    
    Tollbooth() {
    carCount = 00 ;
    cashTotal=0.0 ;
    payingCarCount = 0; 
    noPayCarCount = 0;
    }

    void payingCar() {
        carCount++;
        cashTotal = cashTotal + 0.50;
        payingCarCount++;
    }
    void nopayCar() {
        carCount++;
        noPayCarCount++;
    }
    void printOnConsol() const {
        cout << "Total number of cars: " << carCount <<endl;
        cout << "Total amount of money collected: $" << cashTotal <<endl;
        cout << "Number of paying cars: " << payingCarCount <<endl;
        cout << "Number of non-paying cars: " << noPayCarCount <<endl;
    }
};

int main() 
{
int choice;
    Tollbooth t1;

    do{
        cout<<"1.Add New car and paying toll -"<<endl;
        cout<<"2.Add New car and without paying toll -"<<endl;
        cout<<"3.Show details till now - "<<endl;
        cout<<"4.Exit - " <<endl;
        cout<<"Enter choice"<<endl;
        cin>>choice;
            switch(choice)
                    {
                        case 1: t1.payingCar();
                                break;
                        case 2: t1.nopayCar();
                                break;
                        case 3: t1.printOnConsol();
                                break;
                        case 4: cout<<"Exiting....";
                                return 0;
                    }  
    }while(choice!=4);
return 0;
}