#include<iostream>
#include"vector.h"
#include"node-stack-queue.h"
#include <windows.h>
#include"gingil-bingil.h"
using namespace std;


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











int capacity;
int deadCapacity;
int main()
{
	
	//startShowOff();

	int ncastle=0;
	int roadlength=0;
	int speedOfsoldiers=0;
	int nsoldier=0;
	int soldierPower = 0;
	cout << "welcome to CLASH OF DS"<<endl;
	cout << "Enter number of castles:" << endl;
	cin >> ncastle;

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
		}
	}


	for (int i = 0; i < ncastle; i++)
	{
		cout << "Enter number of soldier in castle " << i << " :" << endl;
		cin >> nsoldier;
		for (int j = 0; j < nsoldier; j++)
		{
			cout << "Enter soldier " << j << " power:" << endl;
			cin >> soldierPower;
		}

	}

	return 0;
}