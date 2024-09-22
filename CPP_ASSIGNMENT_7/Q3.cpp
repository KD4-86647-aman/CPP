#include <iostream>
#include <string>
using namespace std;

enum EAccountType
{
    SAVING,
    CURRENT,
    DMAT
};

class InsufficientFundsException
{
    int accno;
    double currentBalance;
    double withdrawAmount;

public:
    InsufficientFundsException(int accno, double currentBalance, double withdrawAmount)
    {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawAmount = withdrawAmount;
    }

    void display()
    {
        cout << "Insufficient funds in account no " << accno << ". Current balance: " << currentBalance
             << ", attempted to withdraw: " << withdrawAmount << endl;
    }
};

class Account
{
    int accno;
    EAccountType accountType;
    double balance;

public:
    Account() {}

    Account(int accno, EAccountType accountType, double balance)
    {
        this->accno = accno;
        this->accountType = accountType;
        this->balance = balance;
    }

    void accept()
    {
        int accType;
        cout << "Enter the Account Number: ";
        cin >> accno;
        cout << "Enter the Account Type (0: Saving, 1: Current, 2: DMAT): ";
        cin >> accType;
        accountType = static_cast<EAccountType>(accType);
        cout << "Enter the balance: ";
        cin >> balance;
    }

    void display()
    {
        string type;
        switch (accountType)
        {
        case SAVING:
            type = "Saving";
            break;
        case CURRENT:
            type = "Current";
            break;
        case DMAT:
            type = "DMAT";
            break;
        }
        cout << "Account No: " << accno << "\nAccount Type: " << type << "\nBalance: " << balance << endl;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw InsufficientFundsException(accno, balance, amount);
        }
        else if (amount <= 0)
        {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }

    int getAccNo() const
    {
        return accno;
    }
};

int main()
{
    Account accounts[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter details for account " << i + 1 << endl;
        accounts[i].accept();
    }

    int choice, accNo;
    double amount;
    while (true)
    {
        cout << "\nMenu:\n1. Deposit\n2. Withdraw\n3. Display Account\n4. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 4)
            break;

        cout << "Enter Account Number: ";
        cin >> accNo;

        Account *selectedAccount = NULL;
        for (int i = 0; i < 5; i++)
        {
            if (accounts[i].getAccNo() == accNo)
            {
                selectedAccount = &accounts[i];
                break;
            }
        }

        if (!selectedAccount)
        {
            cout << "Account not found.\n";
            continue;
        }

        try
        {
            switch (choice)
            {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                selectedAccount->deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                selectedAccount->withdraw(amount);
                break;
            case 3:
                selectedAccount->display();
                break;
            default:
                cout << "Invalid choice.\n";
            }
        }
        catch (InsufficientFundsException &e)
        {
            e.display();
        }
        catch (invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
