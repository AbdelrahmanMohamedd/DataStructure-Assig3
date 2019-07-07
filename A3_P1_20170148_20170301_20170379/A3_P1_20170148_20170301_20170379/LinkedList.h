#ifndef LinkedList_H
#define LinkedList_H

#include "Node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class LinkedList
{
private:
	int length;
	Node* head;
	Node* tail;

public:
	//Iterator Class.
	class Iterator
	{
	private:
		Node* current;

	public:
		Iterator();
		Iterator(Node*);
		int operator*();
		Node* get_current() const;
		Iterator operator++();
		Iterator operator++(int);
		Iterator operator--();
		Iterator operator--(int);
		friend bool operator==(const Iterator&, const Iterator&);
		friend bool operator!=(const Iterator&, const Iterator&);
	};
	//Constructors.
	LinkedList();
	LinkedList(const int& number, const int& times);
	LinkedList(const LinkedList&);
	//Destructor.
	~LinkedList();
	//Return the length of the list.
	int get_length() const;
	//Insert at a specific location.
	Iterator insert(const int& value, const Iterator&);
	//Push functions.
	void push_back(const int&);
	void push_front(const int&);
	//Pop functions.
	void pop_back();
	void pop_front();
	Iterator erase(const Iterator&);
	Iterator begin() const;
	Iterator end() const;
	void operator= (const LinkedList&);

};
#endif //LinkedList_H

