#include<iostream>
#include"Tree.h"
#include"Node.h"
using namespace std;

Tree::~Tree()
{
	deleteAllSubTree(root);
	delete root;
	root = nullptr;
}

void Tree::deleteAllSubTree(Node* t)
{
	if (t->answersList.empty()) return;
	while (!t->answersList.empty())
	{
		deleteAllSubTree(t->answersList.front()->son);
		delete t->answersList.front()->son;
		t->answersList.front()->son = nullptr;
		t->answersList.pop_front();
	}
}

Node* Tree::search(Node* p, string val, Node*& parent)
{
	if (p->value == val)
		return p;
	if (p->answersList.empty())
		return nullptr;
	Node* temp = nullptr;
	list<Answer*>::iterator it = p->answersList.begin();
	parent = p;
	if (!p->answersList.empty())
		for (; it != p->answersList.end(); it++)
			temp = search((*it)->son, val, parent);
	if (temp == nullptr)
		return nullptr;
	else
		return temp;
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	Node* parent;
	Node* theNeededQue = search(root, fatherquestion, parent);
	if (theNeededQue)
	{
		Answer* a = new Answer(newanswer, new Node(newval));
		theNeededQue->answersList.push_back(a);
		return true;
	}
	return false;
}

void Tree::print(Node* p, int level)
{
	for (int i = 0; i < level; i++) cout << " ";
	cout << p->value << endl;
	if (p->answersList.empty())
		return;
	list<Answer*>::iterator it = p->answersList.begin();
	for (; it != p->answersList.end(); it++)
	{
		for (int i = 0; i < (level); i++) cout << " ";
		cout << ":" << (*it)->ans << endl;
		print((*it)->son, (level + 1));
	}
}

void Tree::searchAndPrint(string val)
{
	if (!searchAndPrint(root, val))
		cout << "Value not found" << endl;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	Node* parent;
	Node* printNode = search(p, val, parent);
	if (!printNode)
		return false;
	cout << printNode->value;
	while (printNode != root)
	{
		printNode = search(root, parent->value, parent);
		cout << "=>" << printNode->value;
	}
	return true;
}

void Tree::searchAndPrintArea(string val)
{
	Node* parent;
	Node* area = search(root, val, parent);
	if (area) print(root);
}

void Tree::deleteSubTree(string val)
{
	Node* parent;
	Node* subTree = search(root, val, parent);
	if (subTree) deleteAllSubTree(subTree);
}

void Tree::process(Node* p)
{
	string ans;
	cout << p->value << endl;
	if (p->answersList.empty())
		return;
	cin >> ans;
	list<Answer*>::iterator it = p->answersList.begin();
	for (; it != p->answersList.end(); it++)
	{
		if ((*it)->ans == ans)
		{
			process((*it)->son);
			break;
		}
	}
}