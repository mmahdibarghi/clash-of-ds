#include<iostream>
#include"vector.h"
#include"node-stack-queue.h"
#include <windows.h>
#include"gingil-bingil.h"
using namespace std;
int capacity;
int deadCapacity;
int idCounter=0;
int speedOfsoldiers = 0;
int ncastle = 0;
int days;
int theWinner = 0;
class path;
class soldier;
class army;
class castle;

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


class gate
{
public:
	gate();
	~gate();
	gate(castle* mycastle);
private:
	//TO DO : fibo tree for attacks
	//queue for all soldier wait to attak
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
	void addInPath(path* inPath,gate& ingate);
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
	//TO DO: AVL tree of soldiers;

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

void castle::addInPath(path * inPath,gate& ingate)
{
	inpath.push_back(inPath);
	gates.push_back(ingate);
}

void castle::addSoldier(soldier & newSoldier)
{
	//TO DO: Add new soldier to avl tree of allSoldier
}

int castle::getNum()
{
	return num;
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
private:
	int power;
	castle* home;
	path* pathWhereIs;
	castle* castleWhereIs;

};

soldier::soldier()
{
	pathWhereIs = nullptr;
	power = 0;

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