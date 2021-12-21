#pragma once
#include<iostream>
#include<string>
using namespace std;


class Trie
{

protected:
	class TrieNode
	{
	public:
		class TrieNode* children[25];
		TrieNode* parent;
		bool isEndOfWord = false;
		TrieNode() { parent = NULL; }
	};
	TrieNode* root;

public:
	Trie() { root = new TrieNode(); } // constructor
	void insert(string word);
	bool del(string word);
	bool search(string word);
	bool printAutoSuggestions(string str);

private:	
	void insert(TrieNode* root, string key);
	void remove(TrieNode* end);
	TrieNode* search(TrieNode* root, string key);	
	void PrintAllWordsFromPrefix(TrieNode*, string s);
	bool isNotLeaf(TrieNode* node);
};
