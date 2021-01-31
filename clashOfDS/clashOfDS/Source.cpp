#include<iostream>
#include"vector.h"
#include"node-stack-queue.h"





class path;
class soldier;
class army;

class gate
{
public:
	gate();
	~gate();

private:
	//TO DO : fibo tree for attacks
	//queue for all soldier wait to attak
	int waitSoldier;

};

gate::gate()
{
}

gate::~gate()
{
}

class castle
{
public:
	castle();
	~castle();

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
	//TO DO: AVL tree of soldiers;

};

castle::castle()
{
}

castle::~castle()
{
}




class path
{
public:
	path();
	~path();
	

private:
	int length;
	int step;
	castle* from;
	castle* to;
	vector<army*> inRoad;
};

path::path()
{
}

path::~path()
{
}










class soldier
{
public:
	soldier();
	~soldier();

private:
	int power;
	castle* home;
	path* pathWhereIs;
	castle* castleWhereIs;

};

soldier::soldier()
{
}

soldier::~soldier()
{
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













int main()
{



	return 0;
}