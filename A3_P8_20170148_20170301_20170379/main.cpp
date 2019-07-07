#include <iostream>
#include <stack>
#include<queue>
using namespace std;

class stackbyqueue
{
private:
    queue<int> q;
public:
    int top()
    {
        return q.back();
    }
    void pop ()
    {
        int s = q.size();
        for (int i = 0; i < s-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
q.pop();
    }
    void push(int value)
    {
        q.push(value);
    }
};

int main()
{

    stackbyqueue qe;
    qe.push(5);
    qe.push(8);
    qe.push(1);
    qe.push(4);
    qe.push(3);

    cout << qe.top() << endl;
    qe.pop();
    cout << qe.top() << endl;
    qe.pop();
    cout << qe.top() << endl;
    qe.pop();
    cout << qe.top() << endl;
    qe.pop();
    cout << qe.top() << endl;
    qe.pop();

    return 0;
}
