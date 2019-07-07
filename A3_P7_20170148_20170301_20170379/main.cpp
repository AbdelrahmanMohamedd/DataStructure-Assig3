#include <iostream>

using namespace std;
struct node {
 string information;
   int priority;
   node *next;
};

class priority_Queue
{
 private:
    node *first;

 public:
    priority_Queue()
    {
        first = NULL;
    }

    void enqueue(string value, int priority)
    {
      node *n = new node , *temp, *temp2;
      n->information = value;
      n->priority = priority;

       if (first == NULL) {
          first = n;
          n->next = NULL;
       }
       else if (priority > first->priority)
       {
          n->next = first;
          first = n;
       }
        else
        {
          temp = first;
          temp2 = NULL;
          while (temp != NULL && temp->priority >= priority)
          {
          temp2 = temp;
          temp=temp->next;
          }
          temp2->next = n;
          n->next = temp;
        }
     }
     string dequeue() {
           node *temp;
           string word = "";

           if(first == NULL)
           cout<<"Empty\n";

           else {
              word = first -> information;
              temp = first;
              first= first->next;
              delete temp;
           }
           return word;
        }
};


int main() {
      priority_Queue P;
      P.enqueue("World",10);
      P.enqueue("Hello",5);
      cout << P.dequeue() << "  " << P.dequeue() << endl;
      return 0;
}
