#include <iostream>
#include "LinkedList.h"

using namespace std;
void print_linked_list_while(const LinkedList&);
void print_linked_list_for(const LinkedList&);

int main()
{
	LinkedList list1;
	LinkedList::Iterator it = list1.begin();
	cout << "Insert Test." << endl;
	cout << "Insert into empty List." << endl;
	it = list1.insert(1, it);
	print_linked_list_for(list1);
	cout << *it << endl;
	cout << "Length :" << list1.get_length() << endl << endl;
	cout << "Insert into the end of the list." << endl;
	it = list1.end();
	it = list1.insert(3, it);
	print_linked_list_for(list1);
	cout << *it << endl;
	cout << "Length :" << list1.get_length() << endl << endl;
	cout << "Insert into the beginning of the list." << endl;
	it = list1.begin();
	it = list1.insert(0, it);
	print_linked_list_while(list1);
	cout << *it << endl;
	cout << "Length :" << list1.get_length() << endl << endl;
	cout << "Insert into the middle of the list." << endl;
	it++;
	it++;
	it = list1.insert(2, it);
	print_linked_list_while(list1);
	cout << *it << endl;
	cout << "Length :" << list1.get_length() << endl << endl;

	cout << "Erase Test." << endl;
	LinkedList list2;
	//Empty List Case.
	cout << "Empty List Case" << endl;
	LinkedList::Iterator it2 = list2.begin();
	it2 = list2.erase(it2);
	cout << *it2 << endl;
	cout << "length :" << list2.get_length() << endl;
	//The Iterator points to the end.
	cout << "The Iterator points to the end." << endl;
	it2 = list2.end();
	it2 = list2.erase(it2);
	cout << *it2 << endl;
	cout << "length :" << list2.get_length() << endl;
	//From The Beginning and only one element.
	cout << "From The Beginning and only one element." << endl;
	list2.push_back(1);
	print_linked_list_for(list2);
	it2 = list2.begin();
	it2 = list2.erase(it2);
	print_linked_list_for(list2);
	cout << *it2 << endl;
	cout << "length :" << list2.get_length() << endl;
	//From The Beginning. 
	cout << "From The Beginning." << endl;
	list2.push_front(2);
	list2.push_front(1);
	list2.push_back(3);
	it2 = list2.begin();
	print_linked_list_while(list2);
	it2 = list2.erase(it2);
	print_linked_list_while(list2);
	cout << *it2 << endl;
	cout << "length :" << list2.get_length() << endl;
	//From The End.
	cout << "From The End." << endl;
	it2 = list2.end(); it2--;
	print_linked_list_for(list2);
	it2 = list2.erase(it2);
	print_linked_list_for(list2);
	cout << *it2 << endl;
	cout << "length :" << list2.get_length() << endl;
	//From The Middle.
	cout << "From The Middle." << endl;
	list2.push_front(1);
	list2.push_front(0);
	list2.push_back(3);
	list2.push_back(4);
	print_linked_list_while(list2);
	it2--; it2--; it2--;
	it2 = list2.erase(it2);
	print_linked_list_while(list2);
	cout << *it2 << endl;
	cout << "length :" << list2.get_length() << endl;
	//Assignment Operator.
	cout << "Assignment Operator." << endl;
	LinkedList list3(10, 6);
	print_linked_list_for(list3);
	list3 = list2;
	print_linked_list_for(list2);
	print_linked_list_for(list3);
	system("Pause");
	return 0;
}

void print_linked_list_while(const LinkedList& list)
{
	LinkedList::Iterator it = list.begin();
	while (it != list.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void print_linked_list_for(const LinkedList& list)
{
	for (LinkedList::Iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}