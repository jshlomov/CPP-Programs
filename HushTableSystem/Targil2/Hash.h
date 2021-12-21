#pragma once
#include<iostream>
#include<math.h>
using namespace std;

enum state { empty, full, deleted };
using ::state;

template <class T, class K>
class Hash
{
protected:
	class Item
	{
	public:
		T data;
		K key;
		state status;
		Item() { status = state::empty; }
		Item(T d, K k, state f) { data = d; key = k; status = f; }
	};

public:
	Item* table;
	int size;
	Hash(int mySize);
	virtual ~Hash();
	virtual int h1(K k) = 0;
	virtual int h2(K k) = 0;
	int hash(K key, int i = 0);
	int search(K key);
	void insert(K key, T data);
	void remove(K key);
	void print();

private:
	/// <summary>
	/// checking if thenumber is a prime number.
	/// </summary>
	bool isPrime(int number)
	{
		while (number)
		{
			double sqr = sqrt(number);
			for (int i = 2; i <= sqr; i++)
				if (number % i == 0)
				{
					return false;
				}
			return true;
		}
	}

	/// <summary>
	/// return the nearest prime number to this number.
	/// </summary>
	int nearPrimeNum(int num)
	{
		if (num % 2 == 0) num++;
		while (!isPrime(num)) num += 2;
		return num;
	}
};

template <class T, class K>
Hash<T, K>::Hash(int mySize)
{
	size = nearPrimeNum(mySize);
	table = new Item[size];
}

template <class T, class K>
Hash<T, K>::~Hash()
{
	delete[] table;
	table = nullptr;
}

/// <summary>
///hash function using h1 and h2 
/// </summary>
template <class T, class K>
int Hash<T, K>::hash(K key, int i)
{
	return (h1(key) + (i * h2(key)) % (size));
}

/// <summary>
/// inserting item to the data (updating if it already exist.)
/// </summary>
template <class T, class K>
void Hash<T, K>::insert(K key, T data)
{
	int x = search(key);
	if (x != -1)
	{
		table[x].data = data; //updating
		return;
	}
	int i = 0;
	while (i != size)
	{
		x = hash(key, i);
		if (table[x].status != state::full)
		{
			table[x].data = data;
			table[x].key = key;
			table[x].status = full;
			return;
		}
		i++;
	}
}

/// <summary>
/// searching in the data
/// </summary>
template <class T, class K>
int Hash<T, K>::search(K key)
{
	int i = 0;
	int location = hash(key, i);
	while ( i < this->size && this->table[location].status != ::empty)
	{
		if (this->table[location].key == key && this->table[location].status == ::full) // identical key and item is  valid
			return location;
		i++;
		location = hash(key, i);
	}
	return -1;
}

/// <summary>
/// delete item from the data
/// </summary>
template <class T, class K>
void Hash<T, K>::remove(K key)
{
	int x = search(key);
	if (x == -1)
		cout << "ERROR\n";
	table[x].status = ::deleted;
}

/// <summary>
/// print all of the data
/// </summary>
template <class T, class K>
void Hash<T, K>::print()
{
	for (int i = 0; i < size; i++)
		if (table[i].status == ::full) cout << ":  " << table[i].data << endl;
	cout << endl;
}
