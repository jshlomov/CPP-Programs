#include "Huffman.h"
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>


int main()
{
	char choice;
	string word, order, format, binaryText;
	int sum;

	HuffmanTree* t;
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':
			cout << "enter the original text\n";
			cin >> word;
			t = new HuffmanTree(word);
			cout << "The encoded string is:\n";
			cout << t->numOfLetters << endl;
			cout << t->lettersOrder << endl;
			cout << t->treeFormat << endl;
			cout << t->binaryResult << endl;			
			break;

		case 'D':
			cout << "enter n\n";
			cin >> sum;
			cout << "enter the letters\n";
			cin >> order;
			cout << "enter the encoded\n";
			cin >> format;
			cout << "enter the encoded text\n";
			cin >> binaryText;
			t = new HuffmanTree(sum, order, format, binaryText);
			cout << "The decoded string is:\n";
			cout << t->text;
		}

	} while (choice != 'X');
	return 0;
}