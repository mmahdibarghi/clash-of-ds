#include<iostream>
#include"vector.h"
#include"node-stack-queue.h"





class path;
class soldier;


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
	castle* from;
	castle* to;

private:
	int length;

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