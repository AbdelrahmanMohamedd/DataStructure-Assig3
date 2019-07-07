#ifndef Node_H
#define Node_H
#include<iostream>
class Node
{
private:
	int value;
	Node* next;
	Node* previous;

public:
	//Constructors.
	Node();
	Node(const int&);
	Node(const int&, Node* next, Node* previous);
	//Destructors.
	~Node();
	//Setters.
	void set_value(const int&);
	void set_next(Node*);
	void set_previous(Node*);
	//Getters.
	int get_value() const;
	Node* get_next() const;
	Node* get_previous() const;
};
#endif // Node_H
