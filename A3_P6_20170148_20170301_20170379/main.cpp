#include <iostream>
#include <string>
using namespace std;

const int size = 20;
template <class T>
class Queue
{
public:
    int Back = -1;
    int top = 0;
    T *values = new T[size];

    Queue()
    {} // default constructor
    Queue( T values[], int size )     //parameterized constructor
    {
        for(int i=0 ; i<size ; i++)
        {
            this->values[i] = values[i];
            Back++;
        }
    }
    void push( T value)   // push func
    {
        Back++;
        values[Back]= value;
    }
    T Front()     //Top  Func
    {
        return values[top];
    }
    void pop()      // pop   func
    {
        top++;
    }
    int sizee()    //size  func
    {
        return Back+1-top;
    }
    ~Queue()   //destructor
    {
        delete[] values;
    }
};

int main()
{
    Queue<int> x;
    x.push(8);
    x.push(1);
    x.push(7);
    x.push(0);
    x.pop();
    x.pop();
    cout << "Front :" << x.Front() << endl;
    cout << "Sizee :" << x.sizee() << endl;
    char arr[]= {'z','c','x','n','b','q','d','i','#','t'};
    Queue<char> z(arr,10);
    cout << "Front :" << z.Front() << endl;
    z.pop();
    cout << "Front :" << z.Front() << endl;
    cout << "Sizee :" << z.sizee() << endl;
}
