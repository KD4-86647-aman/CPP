#include <iostream>
using namespace std;

class Stack
{
    int *stack;
    int top;
    int sizeOfStack;

public:
    Stack(int size = 5)
    {
        stack = new int[size];
        top = -1;
        this->sizeOfStack = size;
    }

    ~Stack()
    {
        delete[] stack;
    }

    void push(int element)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = element;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int ele = stack[top--];
        return ele;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return stack[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == sizeOfStack - 1;
    }

    void print()
    {
        cout << "This is the print method" << endl;
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "Stack Operations" << endl;
    int choice = 0;
    Stack *stack = new Stack();

    do
    {
        cout << "\nChoose the operation to be performed on the stack -" << endl;
        cout << "1. Initialize stack with default size." << endl;
        cout << "2. Initialize stack with customized size." << endl;
        cout << "3. Print stack" << endl;
        cout << "4. Push into stack." << endl;
        cout << "5. Pop from stack" << endl;
        cout << "6. Peek into stack" << endl;
        cout << "7. Check isEmpty()" << endl;
        cout << "8. Check isFull()" << endl;
        cout << "9. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            delete stack;
            stack = new Stack();
            cout << "Stack initialized with default size." << endl;
            break;
        }
        case 2:
        {
            cout << "Enter the size of stack: ";
            int size;
            cin >> size;
            delete stack;
            stack = new Stack(size);
            cout << "Stack initialized with size " << size << "." << endl;
            break;
        }
        case 3:
        {
            stack->print();
            break;
        }
        case 4:
        {
            cout << "Enter the element to push: ";
            int ele;
            cin >> ele;
            stack->push(ele);
            break;
        }
        case 5:
        {
            int poppedElement = stack->pop();
            if (poppedElement != -1)
            {
                cout << "Element " << poppedElement << " popped out of the stack." << endl;
            }
            break;
        }
        case 6:
        {
            int topElement = stack->peek();
            if (topElement != -1)
            {
                cout << "The top element of the stack is " << topElement << "." << endl;
            }
            break;
        }
        case 7:
        {
            if (stack->isEmpty())
            {
                cout << "The stack is empty." << endl;
            }
            else
            {
                cout << "The stack is not empty." << endl;
            }
            break;
        }
        case 8:
        {
            if (stack->isFull())
            {
                cout << "Yes, the stack is full." << endl;
            }
            else
            {
                cout << "No, the stack is not full." << endl;
            }
            break;
        }
        case 9:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice! Please choose a valid operation." << endl;
            break;
        }
        }
    } while (choice != 9);

    delete stack;
    return 0;
}
