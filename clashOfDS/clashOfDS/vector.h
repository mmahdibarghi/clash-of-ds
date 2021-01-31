#pragma once
#include<iostream>
using namespace std;
template <class T>
class vector
{
public:
	vector();
	vector(const vector& lastVector);
	vector(T firstElement, T lastElement);
	vector(int vectorSize);
	~vector();
	int getSizeOfFullBlocks(void);
	int getSizeOfAlocateMemory(void);
	void push_back(T input);
	void pop_back();
	void push_front(T input);
	void pop_front();
	void insert(int index, T input);
	void erase(int index);
	T& find(T search);
	T& operator[](int i);
	void print();
	void fullCheck();
	void emptyCheck();

private:
	int size;
	int fullBlocks;
	T* head;
};


/////////////////////////////////////////////////////////////////////////////
template <class T>
vector<T>::vector()
{
	size = 1;
	fullBlocks = 0;
	head = new T[size];
}

template<class T>
vector<T>::vector(const vector &lastVector)
{
	this->fullBlocks = lastVector.fullBlocks;
	this->size = lastVector.size;
	this->head = new T[size];
	for (int i = 0; i < fullBlocks; i++)
	{
		this->head[i] = lastVector.head[i];
	}
}

template<class T>
vector<T>::vector(T firstElement, T lastElement)
{
	size = lastElement - firstElement;
	fullBlocks = size;
	head = new T[size];
	for (int i = 0; i < fullBlocks; i++)
	{
		head[i] = firstElement + i;
	}
}
template<class T>
vector<T>::vector(int vectorSize)
{
	this->size = vectorSize;
	fullBlocks = 0;
	head = new T[size];
}
///////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
vector<T>::~vector()
{
	delete[] head;
}


//////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int vector<T>::getSizeOfFullBlocks(void)
{
	return fullBlocks;
}

template<class T>
int vector<T>::getSizeOfAlocateMemory(void)
{
	return size;
}
///////////////////////////////////////////////////////////////////////////////////////
template<class T>
void vector<T>::push_back(T input)
{
	fullCheck();
	head[fullBlocks] = input;
	fullBlocks++;

}

template<class T>
void vector<T>::pop_back()
{
	fullBlocks--;
	head[fullBlocks] = NULL;
	emptyCheck();

}

template<class T>
void vector<T>::push_front(T input)
{
	insert(0, input);
}

template<class T>
void vector<T>::pop_front()
{
	erase(0);
	/*
	if (size >= 2 && fullBlocks >= 1)
	{
	T* tmp = head;
	head++;
	free (tmp);
	//head = tmp;
	size--;
	fullBlocks--;
	}
	else if (size == 1)
	{
	head = nullptr;
	}
	*/
}
template<class T>
void vector<T>::insert(int index, T input)
{
	if (index < 0)
	{
		return;
	}

	fullCheck();
	for (int i = fullBlocks - 1; i >= index; i--)
	{
		head[i + 1] = head[i];
	}
	head[index] = input;
	fullBlocks++;
}
template<class T>
void vector<T>::erase(int index)
{
	for (int i = index + 1; i <fullBlocks; i++)
	{
		head[i - 1] = head[i];
	}
	fullBlocks--;
	head[fullBlocks] = NULL;
	emptyCheck();
}
template<class T>
T& vector<T>::find(T search)
{
	for (int i = 0; i < fullBlocks; i++)
	{
		if (head[i] == search)
		{
			return head[i];
		}
	}
	T notfound = NULL;
	return notfound;

}
template<class T>
T& vector<T>::operator[](int i)
{
	if (i > fullBlocks - 1 && i < 0)
	{
		return head[0];
	}
	return head[i];
}
template<class T>
void vector<T>::print()
{
	for (int i = 0; i < fullBlocks; i++)
	{
		cout << head[i] << " ";
	}
	cout << endl;
}
////////////////////////////////////////////////////////////////////
template<class T>
void vector<T>::fullCheck()
{
	if (fullBlocks == size)
	{
		size = ((size + 1) * 3) / 2;
		T* tmp = new T[size];
		for (int i = 0; i < fullBlocks; i++)
		{
			tmp[i] = head[i];
		}
		delete[] head;
		head = tmp;
	}
}

template<class T>
void vector<T>::emptyCheck()
{
	if (size == 1)
	{
		return;
	}
	else if (size - fullBlocks > (size * 2) / 3)
	{
		size = (size * 2) / 3;
		T* tmp = new T[size];
		for (int i = 0; i < fullBlocks; i++)
		{
			tmp[i] = head[i];
		}
		delete[] head;
		head = tmp;
	}
}