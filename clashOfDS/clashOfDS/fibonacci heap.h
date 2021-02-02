#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class fiboNode
{
public:
	fiboNode();
	~fiboNode();
	//data int->soldier&
	fiboNode(int data);
private:
	fiboNode* linkLeft;
	fiboNode* linkRight;
	fiboNode* parent;
	fiboNode* right;
	fiboNode* left;
	fiboNode* nextInheap;
	fiboNode* preINheap;
	bool inlinklist;
	int degree;
	int nodePower;
	int deep;
	int numberOfChild;
	//slodier& data;
	int data;
	friend class fiboHeap;

};
fiboNode::fiboNode(int data)
{
	linkLeft = nullptr;
	linkRight = nullptr;
	parent = nullptr;
	right = nullptr;
	left = nullptr;
	nextInheap = nullptr;
	preINheap = nullptr;
	inlinklist = 1;
	degree = 0;
	deep = 0;
	numberOfChild = 0;
	//data
	nodePower = data;
	this->data = data;
}

fiboNode::fiboNode()
{
}

fiboNode::~fiboNode()
{
}



class fiboHeap
{
public:
	fiboHeap();
	~fiboHeap();
	void insert(int data);
	//data int->soldier&
	int pop(fiboNode* soldierNodeInFibo);
	void makeFibo();
	void mergeTwoHeap(fiboNode* t1Root, fiboNode* t2Root);
	void printFibo();
	fiboNode* popnode(fiboNode* root);
	void insertHeap(fiboNode* whereRoot, fiboNode* what);
	fiboNode* getParent(fiboNode* whereRoot, int childNum, fiboNode* newNode);
	fiboNode* popFromlinklist(fiboNode* popedUp);
	void insrtInLinlist(fiboNode* inRoot);
	void updateDeepDegree(fiboNode* root);
	void updateAll();

private:
	fiboNode* headLinkList;

};

fiboHeap::fiboHeap()
{
	headLinkList = nullptr;
}


fiboHeap::~fiboHeap()
{
}

void fiboHeap::insert(int data)
{
	fiboNode* newNode = new fiboNode(data);
	if (headLinkList == nullptr)
	{
		headLinkList = newNode;
	}
	else
	{
		if (data <= headLinkList->data)
		{
			newNode->linkRight = headLinkList;
			headLinkList->linkLeft = newNode;
			headLinkList = newNode;
		}
		else
		{
			fiboNode* tmp = headLinkList;
			while (tmp->linkRight != nullptr && data > tmp->data)
			{
				tmp = tmp->linkRight;
			}
			if (tmp->linkRight == nullptr)
			{
				tmp->linkRight = newNode;
				newNode->linkLeft = tmp;
			}
			else
			{
				(tmp->left)->right = newNode;
				newNode->right = tmp;
				newNode->linkLeft = tmp->linkLeft;
				tmp->left = newNode;

			}
		}
	}
	this->updateAll();
	this->makeFibo();
	this->updateAll();
}

int fiboHeap::pop(fiboNode* soldierNodeInFibo)
{
	this->updateAll();
	if (headLinkList == nullptr)
	{
		return 0;
	}
	else
	{
		fiboNode* leftChild = soldierNodeInFibo->left;
		fiboNode* rightChild = soldierNodeInFibo->right;
		if (leftChild != nullptr)
		{
			insrtInLinlist(leftChild);

			this->makeFibo();

		}
		else if (rightChild != nullptr)
		{
			insrtInLinlist(rightChild);
			this->makeFibo();

		}
	}
}

void fiboHeap::makeFibo()
{
	fiboNode* i = headLinkList;

	bool isfind = 0;
	while (i != nullptr)
	{
		fiboNode* j = headLinkList->linkRight;
		while (j != nullptr)
		{
			if (i->degree == j->degree)
			{
				isfind = 1;
				mergeTwoHeap(i, j);
				j = i;
			}
			j = j->linkRight;
		}
		i = i->linkRight;
		isfind = 0;
	}
	this->updateAll();
}

void fiboHeap::mergeTwoHeap(fiboNode* t1Root, fiboNode* t2Root)
{
	this->updateAll();
	while (1)
	{
		fiboNode* popingNode = this->popnode(t2Root);
		if (popingNode != nullptr)
		{
			this->insertHeap(t1Root, popingNode);
		}
		else
		{
			popingNode = popFromlinklist(t2Root);
			this->insertHeap(t1Root, popingNode);
			break;
		}
	}
	this->updateAll();
}

void fiboHeap::printFibo()
{
	fiboNode* tmp = headLinkList;
	while (tmp != nullptr)
	{
		fiboNode* go = tmp;
		while (go != nullptr)
		{
			cout << go->nodePower;
			if (go->nextInheap->deep != go->preINheap->deep)
			{
				cout << endl;
			}
			go = go->nextInheap;
		}

		tmp = tmp->linkLeft;
		cout << endl << endl << endl << endl;
	}
}

fiboNode* fiboHeap::popnode(fiboNode* root)
{
	this->updateAll();
	fiboNode* tmp = root;
	while (tmp->nextInheap != nullptr)
	{
		tmp = tmp->nextInheap;
	}
	if (tmp == root)
	{
		this->updateDeepDegree(root);
		return nullptr;
	}
	else
	{
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->preINheap->nextInheap = nullptr;
		tmp->preINheap = nullptr;
		this->updateDeepDegree(root);
		return tmp;
	}
	this->updateAll();
}

void fiboHeap::insertHeap(fiboNode* whereRoot, fiboNode* what)
{
	this->updateAll();
	fiboNode* tmp = whereRoot;
	int v = 1;
	while (tmp->nextInheap != nullptr)
	{
		tmp = tmp->nextInheap;
		v++;
	}
	fiboNode* p = this->getParent(whereRoot, v, what);
	tmp->nextInheap = what;
	what->preINheap = tmp;
	what->parent = p;
	what->deep = p->deep + 1;
	what->degree = 0;
	what->inlinklist = 0;

	tmp = what->parent;
	while (tmp->parent != nullptr)
	{
		if (what->nodePower > tmp->nodePower)
		{
			//data
			//int-> soldier
			int waitData = what->data;
			int waitPower = what->nodePower;
			what->data = tmp->data;
			what->nodePower = tmp->nodePower;
			tmp->data = waitData;
			tmp->nodePower = waitPower;
			what = tmp;
			break;

		}
		tmp = tmp->parent;
	}
	this->updateAll();

}

fiboNode* fiboHeap::getParent(fiboNode* whereRoot, int childNum, fiboNode* newNode)
{
	fiboNode* tmp = whereRoot;
	for (int i = 1; i < childNum / 2; i++)
	{
		tmp = tmp->nextInheap;
	}
	if (childNum % 2)
	{
		tmp->left = newNode;
	}
	else
	{
		tmp->right = newNode;
	}
	tmp->degree++;
	return tmp;
}

fiboNode* fiboHeap::popFromlinklist(fiboNode* popedUp)
{
	(popedUp->linkLeft)->linkRight = popedUp->linkRight;
	(popedUp->linkRight)->linkLeft = popedUp->linkLeft;
	(popedUp->linkLeft) = nullptr;
	(popedUp->linkRight) = nullptr;
	popedUp->inlinklist = 0;
	this->updateAll();
	return popedUp;
}

void fiboHeap::insrtInLinlist(fiboNode* inRoot)
{
	this->updateAll();
	//data
	inRoot->inlinklist = 1;
	inRoot->deep = 0;

	int data = inRoot->data;
	if (data <= headLinkList->data)
	{
		inRoot->linkRight = headLinkList;
		headLinkList->linkLeft = inRoot;
		headLinkList = inRoot;
	}
	else
	{
		fiboNode* tmp = headLinkList;
		while (tmp->linkRight != nullptr && data > tmp->data)
		{
			tmp = tmp->linkRight;
		}
		if (tmp->linkRight == nullptr)
		{
			tmp->linkRight = inRoot;
			inRoot->linkLeft = tmp;
		}
		else
		{
			(tmp->left)->right = inRoot;
			inRoot->right = tmp;
			inRoot->linkLeft = tmp->linkLeft;
			tmp->left = inRoot;

		}
	}
	this->updateAll(); //the best
}

void fiboHeap::updateDeepDegree(fiboNode* root)
{
	fiboNode* tmp = root->nextInheap;
	root->deep = 0;
	int counting = 1;
	while (tmp->nextInheap != nullptr)
	{
		counting++;
		tmp->degree = 0;
		tmp->deep = log2(counting);
		tmp = tmp->nextInheap;
	}

}

void fiboHeap::updateAll()
{
	fiboNode* tmp = headLinkList;
	while (tmp != nullptr)
	{
		this->updateDeepDegree(tmp);
	}
}
