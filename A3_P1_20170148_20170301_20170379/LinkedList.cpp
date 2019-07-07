#include "LinkedList.h"
//Constructors.
LinkedList::LinkedList()
	:length(0), head(NULL), tail(new Node(0, NULL, NULL))
{}
LinkedList::LinkedList(const int& number, const int& times)
{
	if (times <= 0)
	{
		head = NULL;
		tail = new Node(0, NULL, NULL);
		return;
	}
	else
	{
		length = times;
		if (times == 1)
		{
			Node* node = new Node(number);
			node->set_previous(NULL);

			head = node;
			tail = new Node(0, NULL, node);
			node->set_next(tail);
		}
		else
		{
			Node* current = new Node(number);
			current->set_previous(NULL);
			head = current;
			for (int i = 0; i < times - 1; i++)
			{
				Node* new_node = new Node(number);
				current->set_next(new_node);
				new_node->set_previous(current);
				current = new_node;
			}
			tail = new Node(0, NULL, current);
			current->set_next(tail);
		}
	}
}
LinkedList::LinkedList(const LinkedList& RHS)
{
	length = RHS.get_length();
	if (length == 0)
	{
		head = NULL;
		tail = new Node(0, NULL, NULL);
		return;
	}
	LinkedList::Iterator it = RHS.begin();
	Node* current = new Node(*it++);
	current->set_previous(NULL);
	head = current;
	while (it != RHS.end())
	{
		Node* new_node = new Node(*it);
		new_node->set_previous(current);
		current->set_next(new_node);
		current = new_node;
		it++;
	}
	tail = new Node(0, NULL, current);
	current->set_next(tail);
}
//Destructor.
LinkedList::~LinkedList()
{
	while (length > 0)
	{
		pop_front();
	}
	delete tail;
}
//Return the length of the list.
int LinkedList::get_length() const
{
	return length;
}
//Insert at a specific location.
LinkedList::Iterator LinkedList::insert(const int& value, const LinkedList::Iterator& sent_it)
{
	if (head == NULL)
	{
		Node* new_node = new Node(value);
		new_node->set_previous(NULL);
		new_node->set_next(tail);

		head = new_node;
		tail->set_previous(new_node);
		length++;

		LinkedList::Iterator it(new_node);
		return it;
	}
	else if (sent_it == end())
	{
		Node* new_node = new Node(value);
		new_node->set_previous(tail->get_previous());
		tail->get_previous()->set_next(new_node);

		new_node->set_next(tail);
		tail->set_previous(new_node);
		length++;

		LinkedList::Iterator it(new_node);
		return it;
	}
	else if (sent_it == begin())
	{
		Node* new_node = new Node(value);
		new_node->set_previous(NULL);
		new_node->set_next(head);

		head->set_previous(new_node);
		head = new_node;
		length++;

		LinkedList::Iterator it(head);
		return it;
	}
	else
	{
		Node* new_node = new Node(value);
		Node* current = sent_it.get_current();

		new_node->set_previous(current->get_previous());
		new_node->set_next(current);

		current->get_previous()->set_next(new_node);
		current->set_previous(new_node);
		length++;

		LinkedList::Iterator it(new_node);
		return new_node;
	}
}
//Push functions.
void LinkedList::push_back(const int& value)
{
	Node* new_node = new Node(value);
	if (head == NULL)
	{
		new_node->set_previous(NULL);
		new_node->set_next(tail);

		head = new_node;
		tail->set_previous(new_node);
	}
	else
	{
		tail->get_previous()->set_next(new_node);
		new_node->set_previous(tail->get_previous());

		tail->set_previous(new_node);
		new_node->set_next(tail);
	}
	length++;
}
void LinkedList::push_front(const int& value)
{
	Node* new_node = new Node(value);
	if (head == NULL)
	{	
		new_node->set_previous(NULL);
		new_node->set_next(tail);

		head = new_node;
		tail->set_previous(new_node);
	}
	else
	{
		new_node->set_next(head);
		new_node->set_previous(NULL);

		head->set_previous(new_node);
		head = new_node;
	}
	length++;
}
//Pop functions.
void LinkedList::pop_back()
{
	if (head == NULL)
	{
		return;
	}
	else if(head == tail->get_previous())
	{
		delete head;
		head = NULL;
		tail->set_previous(NULL);
	}
	else
	{
		Node* temp = tail->get_previous();
		temp->get_previous()->set_next(tail);
		tail->set_previous(temp->get_previous());
		delete temp;
	}
	length--;
}
void LinkedList::pop_front()
{
	if (head == NULL)
	{
		return;
	}
	else if (head == tail->get_previous())
	{
		delete head;
		head = NULL;
		tail->set_previous(NULL);
	}
	else
	{
		Node* temp = head;
		head = head->get_next();
		delete temp;
	}
	length--;
}
LinkedList::Iterator LinkedList::erase(const LinkedList::Iterator& sent_it)
{
	if (head == NULL || sent_it == end())
	{
		LinkedList::Iterator it(tail);
		return tail;
	}
	else if (sent_it == begin()) //From The Beginning.
	{
		Node* current = head;
		if (current->get_next() == tail)
		{
			Node* current = head;
			delete current;
			length = 0;
			
			head = NULL;
			tail->set_previous(NULL);

			LinkedList::Iterator it(tail);
			return it;
		}
		else
		{
			head = current->get_next();
			current->get_next()->set_previous(NULL);
			delete current;
			length--;

			LinkedList::Iterator it(head);
			return it;
		}
	}
	else //From The End And The Middle.
	{
		Node* current = sent_it.get_current();
		if (current->get_next() == tail)
		{
			current->get_previous()->set_next(tail);
			tail->set_previous(current->get_previous());
			delete current;
			length--;

			LinkedList::Iterator it(tail);
			return it;
		}
		else
		{
			current->get_previous()->set_next(current->get_next());
			current->get_next()->set_previous(current->get_previous());

			LinkedList::Iterator it(current->get_next());
			delete current;
			length--;
			return it;
		}
	}
}
LinkedList::Iterator LinkedList::begin() const
{
	if (head == NULL)
	{
		return tail;
	}
	return head;
}
LinkedList::Iterator LinkedList::end() const
{
	return tail;
}
//Assignment Operator.
void LinkedList::operator= (const LinkedList& RHS)
{
	while(this->length != 0)
	{
		this->pop_back();
	}
	if (RHS.get_length() == 0)
	{
		head = NULL;
		tail->set_previous(NULL);
	}
	else
	{
		LinkedList::Iterator it = RHS.begin();
		while (it != RHS.end())
		{
			this->push_back(*it);
			it++;
		}
	}
}
//Class Iterator.
LinkedList::Iterator::Iterator()
{
	current = NULL;
}
LinkedList::Iterator::Iterator(Node* sent)
{
	current = sent;
}
int LinkedList::Iterator::operator*()
{
	return current->get_value();
}
Node* LinkedList::Iterator::get_current() const
{
	return current;
}
LinkedList::Iterator LinkedList::Iterator::operator++()
{
	if (current->get_next() != NULL)
	{
		current = current->get_next();
	}
	return *this;
}
LinkedList::Iterator LinkedList::Iterator::operator++(int)
{
	Iterator copy = *this;
	if (current->get_next() != NULL)
	{
		current = current->get_next();
	}
	return copy;
}
LinkedList::Iterator LinkedList::Iterator::operator--()
{
	if (current->get_previous() != NULL)
	{
		current = current->get_previous();
	}
	return *this;
}
LinkedList::Iterator LinkedList::Iterator::operator--(int)
{
	Iterator copy = *this;
	if (current->get_previous() != NULL)
	{
		current = current->get_previous();
	}
	return copy;
}
bool operator==(const LinkedList::Iterator& it1, const LinkedList::Iterator& it2)
{
	return it1.current == it2.current;
}
bool operator!=(const LinkedList::Iterator& it1, const LinkedList::Iterator& it2)
{
	return !(it1 == it2);
}