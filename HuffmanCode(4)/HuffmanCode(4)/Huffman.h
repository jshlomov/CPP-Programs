#pragma once
#include<iostream>
#include<string>
#include<queue>
#include <cmath>
#include <list>
using namespace std;

class HuffmanNode
{
public:
	string str;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;
	HuffmanNode() : str(""), frequency(0), left(NULL), right(NULL) {}
	HuffmanNode(char s, int f, HuffmanNode* l = NULL, HuffmanNode* r = NULL)
		: frequency(f), left(l), right(r)
	{
		str += s;
	}
	friend class CompareNode;
};

class compareNode
{
public:
	bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
	{
		return n1->frequency > n2->frequency;
	}
};


class HuffmanTree
{
public:
	string text;
	HuffmanNode* root = new HuffmanNode();
	int numOfLetters = 0;
	string lettersOrder;
	string treeFormat;
	string binaryResult;

	HuffmanTree(string word) : text(word)
	{
		biledTreeByText();
		initializeTreeFormat();
		lettersOrderInit(lettersOrder);
		findResultText(word, binaryResult);
	}

	HuffmanTree(int numOfLetters, string lettersOrder, string TreeFormat, string binaryResult)
		: numOfLetters(numOfLetters), lettersOrder(lettersOrder), treeFormat(TreeFormat), binaryResult(binaryResult)
	{
		biledTreeByFormat();
		findText();
	}

private:

	void findText()
	{
		int i = 0;
		while (i < binaryResult.length())
		{
			findText(root, i);
		}
	}

	void findText(HuffmanNode* hNode, int& i)
	{
		if (!hNode->left && !hNode->right)
		{
			text += hNode->str != "" ? hNode->str : "";
			return;
		}

		if (binaryResult[i] == '0')
		{
			i++;
			findText(hNode->left, i);
		}
		else
		{
			i++;
			findText(hNode->right, i);
		}
	}

	void biledTreeByText()
	{
		int arr[26] = { 0 };
		priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
		for (char i : text)
			arr[i - 'a']++;

		for (int i = 0; i < 26; i++)
		{
			if (arr[i] != 0)
			{
				numOfLetters++;
				pQueue.push(new HuffmanNode('a' + i, arr[i]));
			}
		}

		for (int i = 1; i < numOfLetters; i++) // or: while(!pQueue.empty) does'nt metter
		{
			HuffmanNode* l = pQueue.top();
			pQueue.pop();
			HuffmanNode* r = pQueue.top();
			pQueue.pop();
			if (l->frequency == r->frequency)
				root = new HuffmanNode(NULL, l->frequency + r->frequency, r, l);
			else
				root = new HuffmanNode(NULL, l->frequency + r->frequency, l, r);
			pQueue.push(root);
			pQueue.top();
		}
	}

	void biledTreeByFormat()
	{
		int i = 0;
		int j = 0;
		biledTreeByFormat(root, i);
		putValues(root, j);
	}

	void biledTreeByFormat(HuffmanNode* hNode, int& i)
	{
		if (treeFormat[i] == '1')
			return;
		if (treeFormat[i] == '0')
		{
			hNode->left = new HuffmanNode();
			i++;
			biledTreeByFormat(hNode->left, i);
		}
		i++;
		hNode->right = new HuffmanNode();
		biledTreeByFormat(hNode->right, i);
	}

	void putValues(HuffmanNode* hNode, int& i)
	{
		if (!hNode->left && !hNode->right)
		{
			hNode->str += lettersOrder[i];
			i++;
			return;
		}
		putValues(hNode->left, i);
		putValues(hNode->right, i);
	}

	void findResultText(string word, string& result)
	{
		string s = "";
		for (char i : word)
		{
			findText(root, i, result, s);
			s = "";
		}
	}

	void findText(HuffmanNode* hNode, char ch, string& result, string& s)
	{
		if (hNode == NULL)
			return;

		// found a leaf node
		if (!hNode->left && !hNode->right)
		{
			result += hNode->str[0] == ch ? s : "";
			return;
		}
		findText(hNode->left, ch, result, s += "0");
		//s.pop_back();
		s.erase(s.size() - 1);
		findText(hNode->right, ch, result, s += "1");
		//s.pop_back();
		s.erase(s.size() - 1);
	}

	void initializeTreeFormat()
	{
		format(root, treeFormat);
		treeFormat += "1";
	}

	void format(HuffmanNode* hNode, string& s)
	{
		if (hNode->left)
			s += "0";
		if (!hNode->left)
			return;
		format(hNode->left, s);
		s += "1";
		format(hNode->right, s);
	}

	void lettersOrderInit(string& str)
	{
		lettersOrderInit(root, str);
	}

	void lettersOrderInit(HuffmanNode* hNode, string& str)
	{
		if (hNode == NULL)
			return;
		if (!hNode->left && !hNode->right)
			str += hNode->str;
		lettersOrderInit(hNode->left, str);
		//if (!root->left && !root->right)
		lettersOrderInit(hNode->right, str);
	}
};



