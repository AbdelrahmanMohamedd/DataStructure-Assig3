#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> a(10,3);
	a.push(44);
	a.push(3);
	a.push(11);
	cout << a.top() << endl;
	a.pop();
	a.push(123);
    a.print();
	system("Pause");
    return 0;
}
