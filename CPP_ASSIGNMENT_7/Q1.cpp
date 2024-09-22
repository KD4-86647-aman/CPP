
#include <iostream>
#include <typeinfo>
using namespace std;

class Product
{
    int id;
    string title;
    int price;

public:
    Product() {}

    Product(int id, string title, int price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    virtual void accept()
    {
        cout << "Enter the id of product - ";
        cin >> id;
        cout << "Enter the title of product - ";
        cin >> title;
        cout << "Enter the price of product - ";
        cin >> price;
    }

    virtual void display()
    {
        cout << "ID - " << id << endl;
        cout << "Title - " << title << endl;
        cout << "Price - " << price << endl;
    }
    int getprice()
    {
        return this->price;
    }
};

class Book : public Product
{
    string author;

public:
    Book() : Product() {}

    Book(int id, string title, int price, string author) : Product(id, title, price)
    {

        this->author = author;
    }

    void accept()
    {

        Product::accept();
        cout << "Enter the Author:" << endl;
        cin >> author;
    }

    void display()
    {

        Product::display();
        cout << "Author-  " << author << endl;
    }
};

class Tape : public Product
{

    string artist;

public:
    Tape() : Product() {}

    Tape(int id, string title, int price, string artist) : Product(id, title, price)
    {

        this->artist = artist;
    }

    void accept()
    {

        Product::accept();
        cout << "Enter Artist - ";
        cin >> artist;
    }

    void display()
    {

        Product::display();
        cout << "Artist -  " << artist << endl;
    }
};

float Calculatebill(Product **ptr, int index)
{
    float total = 0;
    for (int i = 0; i < index; i++)
    {
        if (Book *bptr = dynamic_cast<Book *>(ptr[i]))
        {
            int price = bptr->getprice();
            total += (price * 0.90); // 10% discount on books
        }
        else if (Tape *tptr = dynamic_cast<Tape *>(ptr[i]))
        {
            int price = tptr->getprice();
            total += (price * 0.95); // 5% discount on tapes
        }
    }
    return total;
}

int main()
{
    Product *arr[3];
    int choice;
    int index = 0;
    do
    {
        cout << "***************************" << endl;
        cout << "1. Add Tape" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. Display Tapes" << endl;
        cout << "4. Display Books" << endl;
        cout << "5. Calculate bill" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice - ";
        cin >> choice;
        cout << "***************************" << endl;

        switch (choice)
        {
        case 1:
            if (index < 3)
            {
                arr[index] = new Tape;
                arr[index]->accept();
                index++;
            }
            else
                cout << "Products are Full..." << endl;
            break;

        case 2:
            if (index < 3)
            {
                arr[index] = new Book;
                arr[index]->accept();
                index++;
            }
            else
                cout << "Products are Full..." << endl;
            break;

        case 3:
            for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Tape))
                    arr[i]->display();
            break;

        case 4:
            for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Book))
                    arr[i]->display();
            break;

        case 5:
        {
            float totalBill = Calculatebill(arr, index);
            cout << "Total bill after discount: " << totalBill << endl;
        }
        break;

        case 6:
            for (int i = 0; i < index; i++)
            {
                delete arr[i]; // Free allocated memory
            }
            cout << "Exiting from Program... :)" << endl;
            break;

        default:
            cout << "Wrong choice ..." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}