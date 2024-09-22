#include <iostream>
using namespace std;

class Date {

    int day;
    int month;
    int year;

public:

    void acceptDateFromConsole() {
        cout << "Enter day, month, and year: ";
        cin >> day >> month >> year;
    }

    void initDate() {
        day = 1;
        month = 1;
        year = 1900;
    }

    void displayDate() const {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    bool isLeapYear() const {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        return false; 
    }

    int getYear() const {
        return year;
    }
};

int main() {
    Date d1; 

    d1.initDate();
    d1.displayDate(); 

    d1.acceptDateFromConsole(); 
    d1.displayDate(); 

    if (d1.isLeapYear())
        cout << d1.getYear() << " is a leap year." << endl;
    else
        cout << d1.getYear() << " is not a leap year." << endl;

    return 0;
}