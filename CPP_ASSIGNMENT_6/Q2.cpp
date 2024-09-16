#include <iostream>
using namespace std;

class Employee
{
    int id;
    double salary;

public:
    Employee() {}
    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    virtual void accept()
    {
        cout << "Enter empid - ";
        cin >> id;
        cout << "Enter Salary - ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "Empid - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
};

class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus = " << bonus << endl;
    }

public:
    Manager() {}
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
};

class Salesman : virtual public Employee
{
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission = " << commission << endl;
    }

public:
    Salesman() {}
    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }
};

class Salesmanager : public Manager, public Salesman
{
public:
    Salesmanager() {}
    Salesmanager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission)
    {
    }

    void accept()
    {
        Employee::accept();
        Manager::acceptManager();   // Call Manager's acceptManager method
        Salesman::acceptSalesman(); // Call Salesman's acceptSalesman method
    }

    void display()
    {
        Employee::display();
        Manager::displayManager();   // Call Manager's displayManager method
        Salesman::displaySalesman(); // Call Salesman's displaySalesman method
    }
};

int main()
{
    Employee *e = new Salesmanager;
    e->accept();
    e->display();

    return 0;
}
