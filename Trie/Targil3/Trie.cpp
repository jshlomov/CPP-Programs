// Yonatan Shlomov 319217162
// Itzik Nisan 312517261

#include"Trie.h"
#include<iostream>
#include<string>
using namespace std;

/// <summary>
/// If not present, inserts key into trie
/// If the key is prefix of trie node, just
/// marks leaf node
/// </summary>
void Trie::insert(string word)
{
    TrieNode* pNode = search(root, word);
    if (!pNode)
        insert(root, word);
    else if (!pNode->isEndOfWord)
        pNode->isEndOfWord = true;
}

/// <summary>
/// insert word to trie if not exist.
/// </summary>
void Trie::insert(TrieNode* root, string key)
{
	TrieNode* pTrieNode = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
        if (!pTrieNode->children[index])
        {
            pTrieNode->children[index] = new TrieNode();
            pTrieNode->children[index]->parent = pTrieNode;
        }
		pTrieNode = pTrieNode->children[index];
	}
	pTrieNode->isEndOfWord = true;
}

/// <summary>
/// checking if the word exist in trie,
/// and delete it. 
/// </summary>
/// <returns>true if the word deleted, else false</returns>
bool Trie::del(string word)
{
    TrieNode* pNode = search(root, word);
    if (!pNode || !pNode->isEndOfWord) return false;
    else if (isNotLeaf(pNode))
        pNode->isEndOfWord = false;
    else // if it is a leaf
        remove(pNode);
    return true;
}

/// <summary>
/// remove word if the end is a leaf.
/// </summary>
void Trie::remove(TrieNode* end)
{
    TrieNode* pParent = end->parent;
    do
    {
        for (int i = 0; i < 25; i++)
            if (pParent->children[i] == end)
            {
                delete pParent->children[i];
                pParent->children[i] = NULL;
                break;
            }
        end = pParent;
        pParent = pParent->parent;
    } while (pParent->parent != NULL && !end->isEndOfWord && !isNotLeaf(end));
}

/// <summary>
/// checking if the word exist.
/// </summary>
/// <returns>true if the word presents in trie, else false</returns>
bool Trie::search(string word)
{
    return search(root, word) && search(root, word)->isEndOfWord ? true : false;
}

/// <summary>
/// checking if the word exist in trie and
/// Returns the end node of the word if key presents
/// in trie, else null
/// </summary>
Trie::TrieNode* Trie::search(TrieNode* root, string key)
{
    TrieNode* pTrieNode = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pTrieNode->children[index])
            return NULL;

        pTrieNode = pTrieNode->children[index];
    }
    return pTrieNode;
}

/// <summary>
/// the function receives word and print all words from prefix
/// </summary>
/// <returns>true if the received's word exist, else false</returns>
bool Trie::printAutoSuggestions(string str)
{
    TrieNode* pn = search(root, str);
    if (pn == NULL) return false;
    string s = str;
    PrintAllWordsFromPrefix(pn, s);
    return true;
}

/// <summary>
/// print all words that begining with specific word
/// recursion function.
/// </summary>
void Trie::PrintAllWordsFromPrefix(TrieNode* root, string s)
{
    TrieNode* pTN = root;
    if (!pTN) return;
    if (pTN->isEndOfWord)
        cout << s << endl;
    for (int i = 0; i < 25; i++)
    {
        if (pTN->children[i] != NULL)
        {
            s += 'a' + i;
            PrintAllWordsFromPrefix(pTN->children[i], s);
            s.pop_back();
        }
    }
}

/// <summary>
/// check if the TrieNode is not a leaf.
/// </summary>
/// <returns>true: if the TrieNode is'nt a leaf. else false.
bool Trie::isNotLeaf(TrieNode* node)
{
    for (TrieNode* i : node->children)
        if (i != nullptr)
            return true;
    return false;
}
