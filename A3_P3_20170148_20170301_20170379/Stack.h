#include <iostream>
#ifndef STACK_H
#define STACK_H
using namespace std;
template <class T>
struct Node
{
    T value;
    Node<T> *next;
};

template <class T>
class Stack
{
private:
    Node<T> *head;
    int s; //size 
public:
    Stack()
    {
        head = nullptr;
        s = 0;
    }
    Stack(T value, int si)
    {
        for(int i=0;i<si;++i)
        {
            push(value);      /// Stack<int> a;      Stack<int> a(3,5); 3 3 3 3 3
        }
    }
    int Size()
    {
        return s ;
    }
    void push(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        s++;
    }
    void pop()
    {
        Node<T> *temp = new Node<T>;
        temp = head;
        head = head->next;
        s--;
        delete temp;
        s--;
    }
    T& top()
    {
        try
        {
            if(head==nullptr) throw 99;
        }
        catch(int a)
        {
            cout<<"Stack is Empty\n";
        }
        return head->value;
    }
    void print()
    {
        Node<T> *curr = head;
        while(curr!=nullptr)
        {
            cout<<curr->value<< " ";
            curr = curr->next;
        }
		cout << endl;
    }
    ~Stack()
    {
        while(head!=nullptr)
        {
            Node<T> *temp = new Node<T>;
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif // STACK_H
