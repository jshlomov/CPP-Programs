#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Node;

//Answer: for each answer, the string, and the pointer to the node where to continue
class Answer
{
public:
	string ans;
	Node* son;
	Answer(string s, Node* p) { ans = s; son = p; }
};

//Node: each node in the decision tree
class Node
{
	void removeSonValue(string v);
public:
	list<Answer*> answersList;
	string value;
	bool isLeaf;
	Node(string v) { isLeaf = true;  value = v; }

	friend class Tree;
};
