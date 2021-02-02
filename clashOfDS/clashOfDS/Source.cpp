#include<iostream>
#include"vector.h"
#include"node-stack-queue.h"
#include <windows.h>
#include<cmath>
#include<math.h>
#include"gingil-bingil.h"

using namespace std;
int capacity;
double deadCapacity;
int idCounter=0;
int speedOfsoldiers = 0;
int ncastle = 0;
int days;
int theWinner = 0;
class path;
class soldier;
class army;
class castle;
class fiboNode;
class avlNode;
class fiboHeap;
class avlTree;
class gate;
class graphNodes
{
public:
	graphNodes();
	~graphNodes();
	void setCastle(castle* input);
	void addConnection(graphNodes* node);
	void colornodes(castle** dfsarray);
//private:

	castle* showCastle;
	int color;
	vector<graphNodes*> connections;
	int nconnect;
};

graphNodes::graphNodes()
{
	color = 0;
	nconnect = 0;
}

graphNodes::~graphNodes()
{
}

void graphNodes::setCastle(castle * input)
{
	this->showCastle = input;
}

void graphNodes::addConnection(graphNodes * node)
{
	connections.push_back(node);
	nconnect++;
}
int ttnode=0;
void graphNodes::colornodes(castle** dfsarray)
{
	if (this->color == 2)
	{
		return;
	}
	else if(this->color == 1)
	{
		return;
	}
	else
	{
		this->color = 1;
		dfsarray[ttnode]=this->showCastle;
		ttnode++;
		for (int w = 0; w < this->nconnect; w++)
		{
			this->connections[w]->colornodes(dfsarray);
		}
		this->color = 2;
	}
}






class path
{
public:
	path();
	~path();
	path(int length, int step, castle* from, castle* to,gate* outgate);

private:
	int length;
	int step;
	castle* from;
	castle* to;
	vector<army*> inRoad;
	gate* outGate;
};

path::path()
{
	length = 0;
	step = 0;

}

path::~path()
{
}

path::path(int length, int step, castle * from, castle * to,gate* outgate)
{
	this->length = length;
	this->step = step;
	this->from = from;
	this->to = to;
	this->outGate = outgate;
}










class soldier
{
public:
	soldier();
	~soldier();
	soldier(int power, castle* home);
	int getPower();
private:
	int power;
	castle* home;
	path* pathWhereIs;
	castle* castleWhereIs;
	fiboNode* fiboattak;
};

soldier::soldier()
{
	pathWhereIs = nullptr;
	power = -1;
	home = nullptr;
	castleWhereIs = nullptr;
	fiboattak = nullptr;
}

soldier::~soldier()
{
}

soldier::soldier(int power, castle * home)
{
	this->power = power;
	this->home = home;
	this->castleWhereIs = home;
	this->pathWhereIs = nullptr;
	fiboattak = nullptr;
}



int soldier::getPower()
{
	return power;
}








class army
{
public:
	army();
	~army();

private:
	queue<soldier> all;
	int whereInRoad;
};

army::army()
{
}

army::~army()
{
}





/******************************** AVL TREE ***************************************/


class avlNode {


private:
	soldier data;
	int avlNodePower;
	int height;
	avlNode* left;
	avlNode* parent;
	avlNode* right;
	friend class avlTree;
public:
	avlNode(soldier val);
	avlNode();
	int getBalance();
	soldier& getData();
	int getPower();
	int getHeight();
	avlNode* getLeft();
	avlNode* getParent();
	avlNode* getRight();
	void removeParent();
	avlNode* setLeftChild(avlNode* newLeft);
	avlNode* setRightChild(avlNode* newRight);
	int setHeight();
};





avlNode::avlNode(soldier val) {
	data = val;
	avlNodePower = val.getPower();
	height = 0;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

inline avlNode::avlNode()
{
	avlNodePower = 0;
	height = 0;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}



int avlNode::getBalance() {

	int result = 0;
	if (left == nullptr)
	{

		if (right == nullptr)
		{
			result = 0;
		}
		else
		{
			result = -right->height - 1;
		}
	}

	else if (right == nullptr)
	{
		result = left->height + 1;
	}

	else
	{
		result = left->height - right->height;
	}
	return result;
}



soldier& avlNode::getData() {
	return data;
}



int avlNode::getPower() {
	return avlNodePower;
}


int avlNode::getHeight() {
	return height;
}

avlNode* avlNode::getLeft() {
	return left;
}


avlNode* avlNode::getParent() {
	return parent;
}



avlNode* avlNode::getRight() {
	return right;
}



void avlNode::removeParent() {
	parent = nullptr;
}

avlNode* avlNode::setLeftChild(avlNode* newLeft) {

	if (newLeft != nullptr)
		newLeft->parent = this;
	left = newLeft;
	setHeight();
	return left;
}
avlNode* avlNode::setRightChild(avlNode* newRight) {

	if (newRight != nullptr)
		newRight->parent = this;
	right = newRight;
	setHeight();
	return right;
}


int avlNode::setHeight() {


	if (left == nullptr)
	{

		if (right == nullptr)
		{
			height = 0;
		}

		else
		{
			height = right->height + 1;
		}
	}
	else if (right == nullptr)
	{
		height = left->height + 1;
	}
	else if (left->height > right->height)
	{
		height = left->height + 1;
	}

	else
	{
		height = right->height + 1;
	}
	return height;
}








class avlTree {


private:
	avlNode* root;
	avlNode* nearNode;
	soldier nullSoldier;
public:

	
	avlTree();
	avlTree(soldier val);
	void balanceAtavlNode(avlNode* n);
	avlNode* findavlNode(int soldierPower);
	void printSubtree(avlNode* subtree, int depth);
	void rotateLeft(avlNode* n);
	void rotateRight(avlNode* n);
	void setRoot(avlNode* n);
	int getHeight();
	void insert(soldier val);
	void print();
	bool remove(soldier val);
	bool removeByPointer(avlNode* toBeRemoved);
	void findnearNode(avlNode* findRoot, int inpower, int mindis);
	soldier& sendGateWar(int enemysoldierPower);
	soldier& attakToNeighber();
	soldier& findDeepthNode(avlNode*subtree,int depth);
};


avlTree::avlTree() {
	root = nullptr;
	nearNode = nullptr;
}


avlTree::avlTree(soldier val) {
	root = new avlNode(val);

}

void avlTree::balanceAtavlNode(avlNode* n) {

	int bal = n->getBalance();
	//case 1&2
	if (bal > 1) {
		if (n->getLeft()->getBalance() < 0)
		{
			rotateLeft(n->getLeft());
		}
		rotateRight(n);

	}
	//case 3&4
	else if (bal < -1) {
		if (n->getRight()->getBalance() > 0)
		{
			rotateRight(n->getRight());
		}
		rotateLeft(n);
	}
}

avlNode* avlTree::findavlNode(int soldierPower) {


	avlNode* temp = root;
	while (temp != nullptr) {
		if (soldierPower == temp->getPower())
		{
			break;
		}
		else if (soldierPower < temp->getPower())
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}
	return temp;
}


int avlTree::getHeight() {
	return root->getHeight();
}


void avlTree::insert(soldier val) {
	int insertPower = val.getPower();
	if (root == nullptr)
	{
		root = new avlNode(val);
	}
	else {
		avlNode* added_avlNode = nullptr;
		avlNode* temp = root;
		while (temp != nullptr && added_avlNode == nullptr) {

			if (insertPower < temp->getPower()) {
				if (temp->getLeft() == nullptr) {
					added_avlNode = temp->setLeftChild(new avlNode(val));
				}
				else
				{
					temp = temp->getLeft();
				}

			}
			else if (insertPower >= temp->getPower()) {
				if (temp->getRight() == nullptr) {
					added_avlNode = temp->setRightChild(new avlNode(val));
				}
				else
					temp = temp->getRight();

			}

		}

		temp = added_avlNode;
		while (temp != nullptr) {
			temp->setHeight();
			balanceAtavlNode(temp);
			temp = temp->getParent();
		}
	}

}

void avlTree::print() {


	if (root == nullptr)
		cout << "There is no soldier!" << endl;

	else if (root->getHeight() > 4)
		std::cout << "Not currently supported!" <<
		std::endl;

	else {
		int max = root->getHeight();
		for (int depth = 0; depth <= max; depth++) {
			printSubtree(root, depth);
			std::cout << std::endl;
		}
	}
}

void avlTree::printSubtree(avlNode* subtree, int depth) {

	if (depth > 0) {
		if (subtree == nullptr) {
			printSubtree(subtree, depth - 1);
			printSubtree(subtree, depth - 1);
		}
		else {
			printSubtree(subtree->getLeft(), depth - 1);
			printSubtree(subtree->getRight(), depth - 1);
		}

	}
	else if (subtree == nullptr)

		cout << "-" << "	    ";

	else
		cout << subtree->getPower() << " ";
}



bool avlTree::remove(soldier val) {


	avlNode* toBeRemoved = findavlNode(val.getPower());
	if (toBeRemoved == nullptr)
		return false;

	bool isLeft = 0;
	avlNode* p = toBeRemoved->getParent();
	if (p != nullptr && p->getLeft() == toBeRemoved)
	{
		isLeft = 1;
	}
	else
	{
		isLeft = 0;
	}

	if (toBeRemoved->getLeft() == nullptr) {


		if (toBeRemoved->getRight() == nullptr) {


			if (p == nullptr) {
				setRoot(nullptr);
				delete toBeRemoved;


			}
			else {
				if (isLeft)
					p->setLeftChild(nullptr);
				else
					p->setRightChild(nullptr);
				delete toBeRemoved;
				p->setHeight();
				balanceAtavlNode(p);
			}


		}
		else {


			if (p == nullptr) {
				setRoot(toBeRemoved->getRight());
				delete toBeRemoved;
			}
			else {
				if (isLeft)
				{
					p->setLeftChild(toBeRemoved->getRight());
				}
				else
				{
					p->setRightChild(toBeRemoved->getRight());
				}
				delete toBeRemoved;
				p->setHeight();
				balanceAtavlNode(p);
			}
		}
	}

	else if (toBeRemoved->getRight() == nullptr) {


		if (p == nullptr) {
			setRoot(toBeRemoved->getLeft());
			delete toBeRemoved;


		}
		else {
			if (isLeft)
				p->setLeftChild(toBeRemoved->getLeft());
			else
				p->setRightChild(toBeRemoved->getLeft());
			delete toBeRemoved;
			p->setHeight();
			balanceAtavlNode(p);
		}

	}
	else {

		avlNode* replacement;
		avlNode* replacement_parent;
		avlNode* temp_avlNode;
		int bal = toBeRemoved->getBalance();
		if (bal > 0) {

			if (toBeRemoved->getLeft()->getRight() == nullptr)
			{
				replacement = toBeRemoved->getLeft();
				replacement->setRightChild(toBeRemoved->getRight());
				temp_avlNode = replacement;
			}
			else {
				replacement = toBeRemoved->getLeft()->getRight();
				while (replacement->getRight() != nullptr)
					replacement = replacement->getRight();
				replacement_parent = replacement->getParent();
				replacement_parent->setRightChild(replacement->getLeft());
				temp_avlNode = replacement_parent;
				replacement->setLeftChild(toBeRemoved->getLeft());
				replacement->setRightChild(toBeRemoved->getRight());
			}

		}
		else if (toBeRemoved->getRight()->getLeft() == nullptr) {
			replacement = toBeRemoved->getRight();
			replacement->setLeftChild(toBeRemoved->getLeft());
			temp_avlNode = replacement;

		}
		else {
			replacement = toBeRemoved->getRight()->getLeft();
			while (replacement->getLeft() != nullptr)
				replacement = replacement->getLeft();
			replacement_parent = replacement->getParent();
			replacement_parent->setLeftChild(
				replacement->getRight());
			temp_avlNode = replacement_parent;
			replacement->setLeftChild(
				toBeRemoved->getLeft());
			replacement->setRightChild(
				toBeRemoved->getRight());
		}

		if (p == nullptr)
		{
			setRoot(replacement);
		}
		else if (isLeft)
			p->setLeftChild(replacement);
		else
			p->setRightChild(replacement);
		delete toBeRemoved;
		balanceAtavlNode(temp_avlNode);
	}
	return true;
}



bool avlTree::removeByPointer(avlNode * toBeRemoved)
{

	bool isLeft = 0;
	avlNode* p = toBeRemoved->getParent();
	if (p != nullptr && p->getLeft() == toBeRemoved)
	{
		isLeft = 1;
	}
	else
	{
		isLeft = 0;
	}

	if (toBeRemoved->getLeft() == nullptr) {


		if (toBeRemoved->getRight() == nullptr) {


			if (p == nullptr) {
				setRoot(nullptr);
				delete toBeRemoved;


			}
			else {
				if (isLeft)
					p->setLeftChild(nullptr);
				else
					p->setRightChild(nullptr);
				delete toBeRemoved;
				p->setHeight();
				balanceAtavlNode(p);
			}


		}
		else {


			if (p == nullptr) {
				setRoot(toBeRemoved->getRight());
				delete toBeRemoved;
			}
			else {
				if (isLeft)
				{
					p->setLeftChild(toBeRemoved->getRight());
				}
				else
				{
					p->setRightChild(toBeRemoved->getRight());
				}
				delete toBeRemoved;
				p->setHeight();
				balanceAtavlNode(p);
			}
		}
	}

	else if (toBeRemoved->getRight() == nullptr) {


		if (p == nullptr) {
			setRoot(toBeRemoved->getLeft());
			delete toBeRemoved;


		}
		else {
			if (isLeft)
				p->setLeftChild(toBeRemoved->getLeft());
			else
				p->setRightChild(toBeRemoved->getLeft());
			delete toBeRemoved;
			p->setHeight();
			balanceAtavlNode(p);
		}

	}
	else {

		avlNode* replacement;
		avlNode* replacement_parent;
		avlNode* temp_avlNode;
		int bal = toBeRemoved->getBalance();
		if (bal > 0) {

			if (toBeRemoved->getLeft()->getRight() == nullptr)
			{
				replacement = toBeRemoved->getLeft();
				replacement->setRightChild(toBeRemoved->getRight());
				temp_avlNode = replacement;
			}
			else {
				replacement = toBeRemoved->getLeft()->getRight();
				while (replacement->getRight() != nullptr)
					replacement = replacement->getRight();
				replacement_parent = replacement->getParent();
				replacement_parent->setRightChild(replacement->getLeft());
				temp_avlNode = replacement_parent;
				replacement->setLeftChild(toBeRemoved->getLeft());
				replacement->setRightChild(toBeRemoved->getRight());
			}

		}
		else if (toBeRemoved->getRight()->getLeft() == nullptr) {
			replacement = toBeRemoved->getRight();
			replacement->setLeftChild(toBeRemoved->getLeft());
			temp_avlNode = replacement;

		}
		else {
			replacement = toBeRemoved->getRight()->getLeft();
			while (replacement->getLeft() != nullptr)
				replacement = replacement->getLeft();
			replacement_parent = replacement->getParent();
			replacement_parent->setLeftChild(
				replacement->getRight());
			temp_avlNode = replacement_parent;
			replacement->setLeftChild(
				toBeRemoved->getLeft());
			replacement->setRightChild(
				toBeRemoved->getRight());
		}

		if (p == nullptr)
		{
			setRoot(replacement);
		}
		else if (isLeft)
			p->setLeftChild(replacement);
		else
			p->setRightChild(replacement);
		delete toBeRemoved;
		balanceAtavlNode(temp_avlNode);
	}
	return true;
}

soldier & avlTree::attakToNeighber()
{
	return findDeepthNode(this->root, this->getHeight());
}

soldier & avlTree::findDeepthNode(avlNode * subtree, int depth)
{
	if (depth > 0) {
		if (subtree == nullptr) {
			printSubtree(subtree, depth - 1);
			printSubtree(subtree, depth - 1);
		}
		else {
			printSubtree(subtree->getLeft(), depth - 1);
			printSubtree(subtree->getRight(), depth - 1);
		}

	}
	else if (subtree == nullptr)

		return nullSoldier;

	else
		return subtree->getData();
}


void avlTree::findnearNode(avlNode* findRoot, int inpower, int mindis)
{

	if (findRoot != NULL)
	{
		int checker = 0;
		checker = abs(inpower - findRoot->getPower());
		if (checker < mindis)
		{
			mindis = checker;
			nearNode = findRoot;
		}
		findnearNode(findRoot->left, inpower, mindis);
		findnearNode(findRoot->right, inpower, mindis);
	}

	return;
}

 soldier& avlTree::sendGateWar(int enemysoldierPower)
{
	this->findnearNode(root, enemysoldierPower, 1000);
	avlNode* tmp = nearNode;
	nearNode = nullptr;
	return tmp->getData();
}


void avlTree::rotateLeft(avlNode* n) {
	bool isLeft = 0;
	avlNode* p = n->getParent();
	if (p != nullptr && p->getLeft() == n)
		isLeft = 1;
	else
		isLeft = 0;

	avlNode* temp = n->getRight();
	n->setRightChild(temp->getLeft());
	temp->setLeftChild(n);
	if (p == nullptr)
		setRoot(temp);
	else if (isLeft)
		p->setLeftChild(temp);
	else
		p->setRightChild(temp);
}

void avlTree::rotateRight(avlNode* n) {

	bool isLeft = 0;
	avlNode* p = n->getParent();
	if (p != nullptr && p->getLeft() == n)
		isLeft = 1;
	else
		isLeft = 0;


	avlNode* temp = n->getLeft();
	n->setLeftChild(temp->getRight());
	temp->setRightChild(n);


	if (p == nullptr)
		setRoot(temp);
	else if (isLeft)
		p->setLeftChild(temp);
	else
		p->setRightChild(temp);
}

void avlTree::setRoot(avlNode* n) {
	root = n;
	if (root != nullptr)
		root->removeParent();
}










/**************************************************************/









/******************************      Fibonacci heap     **********************************/






class fiboNode
{
public:
	fiboNode();
	~fiboNode();
	//data int->soldier&
	fiboNode(soldier& data);
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
	soldier data;
	friend class fiboHeap;

};
fiboNode::fiboNode(soldier& data)
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
	nodePower = data.getPower();
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
	void insert(soldier& data);
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

void fiboHeap::insert(soldier& data)
{
	fiboNode* newNode = new fiboNode(data);
	if (headLinkList == nullptr)
	{
		headLinkList = newNode;
	}
	else
	{
		if (data.getPower() <= headLinkList->nodePower)
		{
			newNode->linkRight = headLinkList;
			headLinkList->linkLeft = newNode;
			headLinkList = newNode;
		}
		else
		{
			fiboNode* tmp = headLinkList;
			while (tmp->linkRight != nullptr && data.getPower() > tmp->nodePower)
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
			soldier waitData = what->data;
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

	int power = inRoot->nodePower;
	if (power <= headLinkList->nodePower)
	{
		inRoot->linkRight = headLinkList;
		headLinkList->linkLeft = inRoot;
		headLinkList = inRoot;
	}
	else
	{
		fiboNode* tmp = headLinkList;
		while (tmp->linkRight != nullptr && power > tmp->nodePower)
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







/********************************************************************************************/









class gate
{
public:
	gate();
	~gate();
	gate(castle* mycastle);
private:
	fiboHeap warZone;
	queue<soldier> waitToAttack;
	int waitSoldier;
	castle* forWhichCastle;
};

gate::gate()
{
}

gate::~gate()
{
}

gate::gate(castle * mycastle)
{
	this->forWhichCastle = mycastle;
}

class castle
{
public:
	castle();
	~castle();
	void addToNeighbours(path* toPath, castle* neighbours);
	void addInPath(path* inPath, gate& ingate);
	void addSoldier(soldier& newSoldier);
	int getNum();
private:
	int num;
	int owner;
	int publication;
	int nNeighbours;
	vector<castle*> Neighbours;
	vector<path*> outPath;
	vector<path*> inpath;
	stack<soldier> dead;
	vector<gate> gates;
	avlTree allSoldier;


};

castle::castle()
{

	num = idCounter;
	owner = idCounter;
	publication = 0;
	nNeighbours = 0;
	idCounter++;


}

castle::~castle()
{
}

void castle::addToNeighbours(path * toPath, castle * neighbours)
{
	this->nNeighbours++;
	Neighbours.push_back(neighbours);
	outPath.push_back(toPath);
}

void castle::addInPath(path * inPath, gate& ingate)
{
	inpath.push_back(inPath);
	gates.push_back(ingate);
}

void castle::addSoldier(soldier & newSoldier)
{
	allSoldier.insert(newSoldier);
	publication++;
}

int castle::getNum()
{
	return num;
}









int main()
{
	
	//startShowOff();
	int roadlength=0;
	int nsoldier=0;
	int soldierPower = 0;
	cout << "welcome to CLASH OF DS"<<endl;
	cout << "Enter number of castles:" << endl;
	cin >> ncastle;
	castle* allCastles = new castle[ncastle];
	graphNodes* allNodes = new graphNodes[ncastle];
	for (int i = 0; i < ncastle; i++)
	{
		allNodes[i].setCastle(&allCastles[i]);
	}
	cout << "Enter speed of soldiers:" << endl;
	cin >> speedOfsoldiers;
	cout << "Enter output capacity of castles:" << endl;
	cin >> capacity;	
	cout << "Enter output capacity of dead stacks:" << endl;
	cin >> deadCapacity;

	for (int i = 0; i < ncastle; i++)
	{
		for (int j = 0; j < ncastle; j++)
		{
			cout << "Enter length of road from castle " << i << " to castle " << j << " (if there is no way Enter 0)" << endl;
			cin >> roadlength;
			if (roadlength == 0)
			{
				continue;
			}
			else
			{
				gate* newgate = new gate(&allCastles[j]);
				path* fromPath = new path(roadlength, roadlength / speedOfsoldiers, &allCastles[i], &allCastles[j], newgate);
				allCastles[i].addToNeighbours(fromPath, &allCastles[j]);
				allCastles[j].addInPath(fromPath, *newgate);
				allNodes[i].addConnection(&allNodes[j]);
			}
		}
	}


	for (int i = 0; i < ncastle; i++)
	{
		cout << "Enter number of soldier in castle " << i+1 << " :" << endl;
		cin >> nsoldier;
		for (int j = 0; j < nsoldier; j++)
		{
			cout << "Enter soldier " << j << " power:" << endl;
			cin >> soldierPower;
			soldier* newSoldier = new soldier(soldierPower, &allCastles[i]);
			allCastles[i].addSoldier(*newSoldier);
		}

	}
	/***************************      now start making DFS array of castles         *******************************************/
	castle** dfsCastles = new castle*[ncastle];
	allNodes[0].colornodes(dfsCastles);
	/*
	for (int i = 0; i < ncastle; i++)
	{
		cout <<dfsCastles[i]->getNum()<<"   "<<endl;
	}
	*/
	
	
	
	
	
	/*********************************    Now Go for the part & start counting days    *************************************/
	cout << "choose game mode (Enter number of choose):" << endl << "1.play in specific time and days" << endl << "2.play until find the winner" << endl;
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		cout << "Enter how many days do you want to game is in progress:" << endl;
		cin >> days;
		for (int d = 0; d < days; d++)
		{
			for (int c = 0; c < ncastle; c++)
			{
				
			}
		}
	}



















	else
	{
		while (theWinner == 0)
		{
			for (int c = 0; c < ncastle; c++)
			{

			}
		}
	}
	return 0;
}
