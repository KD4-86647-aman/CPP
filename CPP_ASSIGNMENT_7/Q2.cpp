#include <iostream>
#include <typeinfo>
using namespace std;

class Employee
{
    int id;
    double salary;

public:
    Employee()
    {
    }

    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }
    void setid(int id)
    {
        this->id = id;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    int getid()
    {
        return id;
    }
    double getsalary()
    {
        return salary;
    }
    virtual void accept()
    {
        cout << "Enter the Id :";
        cin >> id;
        cout << "Enter the Salary :";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "\nDetails " << endl;
        cout << "ID :" << id << endl;
        cout << "Salary :" << salary << endl;
    }
};

class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {

        cout << "Enter the Bonus :";
        cin >> bonus;
    }
    void displayManager()
    {

        cout << "Bonus :" << bonus << endl;
    }

public:
    Manager()
    {
    }

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
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus()
    {
        return bonus;
    }
};
class Salesman : virtual public Employee
{
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission :";
        cin >> commission;
    }
    void displaySalesman()
    {

        cout << "commission :" << commission << endl;
    }

public:
    Salesman()
    {
    }

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
    void setCommission(double commission)
    {
        this->commission = commission;
    }
    double getCommission()
    {
        return commission;
    }
};
class Salesmanager : public Manager, public Salesman
{

public:
    Salesmanager()
    {
    }
    Salesmanager(int id, double salary, double bonus, double commission) : Employee(id, salary)
    {
        this->setBonus(bonus);
        this->setCommission(commission);
    }
    void accept()
    {

        Employee::accept();
        this->acceptManager();
        this->acceptSalesman();
    }
    void display()
    {
        Employee::display();
        this->displayManager();
        this->displaySalesman();
    }
};
int main()
{
    Employee *arr[5];
    int choice;
    int mcount = 0;
    int scount = 0;
    int smcount = 0;
    int index = 0;
    do
    {
        cout << "***************************" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display the count of all employees with respect to designation" << endl;
        cout << "3. Display All Managers" << endl;
        cout << "4. Display All Salesman" << endl;
        cout << "5. Display All SalesManagers" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice - ";
        cin >> choice;
        cout << "***************************" << endl;
        switch (choice)
        {
        case 1:
        {
            int choice2;

            cout << "1. Accept Manager " << endl;
            cout << "2. Accept Salesman " << endl;
            cout << "3. Accept SalesManager " << endl;
            cin >> choice2;

            switch (choice2)
            {
            case 1:
            {
                if (index < 5)
                {
                    arr[index] = new Manager();
                    arr[index]->accept();
                    mcount++;
                    index++;
                }
                else
                {
                    cout << "Employees Are Full" << endl;
                }
            }
            break;
            case 2:
            {
                if (index < 5)
                {
                    arr[index] = new Salesman();
                    arr[index]->accept();
                    scount++;
                    index++;
                }
                else
                {
                    cout << "Employees Are Full" << endl;
                }
            }
            break;
            case 3:
            {
                if (index < 5)
                {
                    arr[index] = new Salesmanager();
                    arr[index]->accept();
                    smcount++;
                    index++;
                }
                else
                {
                    cout << "Employees Are Full" << endl;
                }
            }
            break;

            default:
                cout << "Invalid input..........";
                break;
            }
        }
        break;
        case 2:
        {
            cout << " Employees:  :" << endl;
            cout << " Manager:  " << mcount << endl;
            cout << " Salesman:  " << scount << endl;
            cout << " Salesmanager:  " << smcount << endl;
        }
        break;
        case 3:
        {
            for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Manager))
                    arr[i]->display();
        }
        break;
        case 4:
        {
            for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Salesman))
                    arr[i]->display();
        }
        break;
        case 5:
        {
            for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Salesmanager))
                    arr[i]->display();
        }
        break;
        default:
            cout << "Exiting from program ....... :)" << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}