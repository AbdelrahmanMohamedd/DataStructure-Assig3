#include "Node.h"

//Constructors.
Node::Node()
	:value(0), next(NULL), previous(NULL)
{}

Node::Node(const int& value)
	:value(value)
{}

Node::Node(const int& value, Node* next, Node* previous)
	:value(value), next(next), previous(previous)
{}
//Destructor.
Node::~Node()
{}
//Setters.
void Node::set_value(const int& value)
{
	this->value = value;
}
void Node::set_next(Node* next)
{
	this->next = next;
}
void Node::set_previous(Node* previous)
{
	this->previous = previous;
}
//Getters.
int Node::get_value() const
{
	return value;
}
Node* Node::get_next() const
{
	return next;
}
Node* Node::get_previous() const
{
	return previous;
}