#pragma once
#include<iostream>
using namespace std;

/*************************   node class   *************************/
template <typename n>
class node
{
public:
	node();
	node(n data, node* next);
	~node();
	n& getdata();
	node* getnext();
	void setnext(node* next);
	//friend class stack<n>;
private:
	n data;
	node<n>* next;
};
template <typename n>
node<n>::node()
{
}
template<typename n>
node<n>::node(n data, node * next)
{
	this->data = data;
	this->next = next;
}
template <typename n>
node<n>::~node()
{
}

template<typename n>
n & node<n>::getdata()
{
	return data;
}

template<typename n>
node<n> * node<n>::getnext()
{
	return next;
}

template<typename n>
void node<n>::setnext(node * next)
{
	this->next = next;
}


/*************************   stack class   *************************/
template <typename t>
class stack
{
public:
	stack();
	~stack();
	void push(t input);
	void pop();
	int getsize();
	void print();
	t& search(t input);
	//friend class node<t>;
private:
	node<t>* head;
	int size;
};

template <typename t>
stack<t>::stack()
{
	head = nullptr;
	size = 0;
}
template <typename t>
stack<t>::~stack()
{
	node<t>* tmp = head;
	while (tmp != nullptr)
	{
		node<t>* ntmp = tmp->getnext();
		delete tmp;
		tmp = ntmp;
	}
}

template<typename t>
void stack<t>::push(t input)
{
	if (size == 0)
	{
		head = new node<t>(input, nullptr);

	}
	else
	{
		node<t>* tmp = new node<t>(input, head);
		head = tmp;

	}
	size++;
}

template<typename t>
void stack<t>::pop()
{
	if (size == 0)
	{
		//throw "empty stack";
		return;
	}
	else
	{
		node<t>*tmp = head;
		head = head->getnext();
		delete tmp;
	}
	size--;
}

template<typename t>
int stack<t>::getsize()
{
	return size;
}

template<typename t>
void stack<t>::print()
{
	node<t>* tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->getdata() << " ,";
		tmp = tmp->getnext();
	}
	cout << endl;
}

template<typename t>
t & stack<t>::search(t input)
{

	node<t>* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->getdata() == input)
		{
			return tmp->getdata();
		}
		tmp = tmp->getnext();
	}
	t n = NULL;
	return n;
}

/*************************   queue class   *************************/
template <typename t>
class queue
{
public:
	queue();
	~queue();
	void push(t input);
	t pop();
	int getsize();
	t& search(t input);
	void print();
private:
	node<t>* rear;
	int size;
};
template <typename t>
queue<t>::queue()
{
	rear = nullptr;
	size = 0;
}
template <typename t>
queue<t>::~queue()
{
	node<t>* tmp;
	tmp = rear;
	while (tmp != nullptr)
	{
		node<t>* x = tmp->getnext();
		delete tmp;
		tmp = x;

	}
}

template<typename t>
void queue<t>::push(t input)
{
	if (size == 0)
	{
		rear = new node<t>(input, nullptr);
	}
	else
	{
		node<t>* tmp = new node<t>(input, rear);
		rear = tmp;

	}
	size++;
}

template<typename t>
t queue<t>::pop()
{
	if (size == 0)
	{
		//throw "queue is empty";
		return NULL;
	}
	node<t>* tmp;
	tmp = rear;
	if (size == 1)
	{
		rear = nullptr;
		size--;
		return tmp->getdata();
	}
	while (tmp->getnext()->getnext() != nullptr)
	{

		tmp = tmp->getnext();
	}
	node<t>* x = tmp;
	tmp = tmp->getnext();
	t result = tmp->getdata();
	delete tmp;
	x->setnext(nullptr);
	size--;
	return result;
}

template<typename t>
int queue<t>::getsize()
{
	return size;
}

template<typename t>
t & queue<t>::search(t input)
{
	node<t>* tmp;
	tmp = rear;
	while (tmp != nullptr)
	{
		if (tmp->getdata() == input)
		{
			return tmp->getdata();
		}
		tmp = tmp->getnext();

	}
	t n = NULL;
	return n;
}

template<typename t>
void queue<t>::print()
{
	node<t>* tmp;
	tmp = rear;
	while (tmp != nullptr)
	{
		cout << tmp->getdata() << " ,";
		tmp = tmp->getnext();

	}
	cout << endl;
}

