#pragma once
#include <iostream>
#include <list>
#include <string>
#include"Node.h"
using namespace std;

//Tree: the Decision Tree
class Tree
{
	Node* root;
	Node* search(Node* p, string val, Node*& parent);
	//returns node t where the string equals val. If t has a prent, the pointer parent will contain its address. 

	bool searchAndPrint(Node* p, string val);
	void print(Node* p, int level = 0);
	void process(Node* p);
public:
	Tree() { root = NULL; }
	~Tree();
	void deleteAllSubTree(Node* t);
	void addRoot(string newval) { root = new Node(newval); }
	bool addSon(string fatherquestion, string newanswer, string newval);
	void searchAndPrint(string val);
	void searchAndPrintArea(string val);
	void printAllTree() { print(root); }
	string printToString(Node* p) { return ""; }
	string printToString() { return printToString(root); }
	void deleteSubTree(string val);
	void process() { process(root); }
};
