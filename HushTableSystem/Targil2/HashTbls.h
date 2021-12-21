#pragma once
#include"HashClient.h"
#include"HashVolunteer.h"
#include<iostream>
#include<string>
#include<list>
using namespace std;

class HashTbls
{
protected:

	HashClient* clients;
	HashVolunteer* volunteers;

public:

	HashTbls(int clientsSize, int volunteersSize)
	{
		clients = new HashClient(clientsSize);
		volunteers = new HashVolunteer(volunteersSize);
	}

	~HashTbls()
	{
		delete clients;
		clients = nullptr;
		delete volunteers;
		volunteers = nullptr;
	}

	/// <summary>
	/// add volunteer to the data
	/// </summary>
	void addVolunteer(Volunteer v) 
	{
		volunteers->insert(v.name, v);
	}

	/// <summary>
	/// delete volunteer from the data.
	/// </summary>
	void delVolunteer(Volunteer v)
	{
		volunteers->remove(v.name);
	}

	/// <summary>
	/// add client to the data
	/// </summary>
	void addClient(Client c)
	{
		clients->insert(c.phone, c);
	}

	/// <summary>
	/// delete client from the data.
	/// </summary>
	void delClient(Client c)
	{
		clients->remove(c.phone);
	}

	/// <summary>
	/// add volunteer to list of volunteers who helped this client.
	/// </summary>
	void addVolunteerToClient(Volunteer v, Client c)
	{
		int x = clients->search(c.phone);
		int y = volunteers->search(v.name);
		if (x == -1 || y == -1)
		{
			cout << "ERROR\n";
			return;
		}
		if (checkIfNotExist(v.name, clients->table[x].data.volunteers)) //checking if the name is already exist, return true if not.
			clients->table[x].data.volunteers.push_back(v.name);
		else
			cout << "ERROR\n";
	}

	/// <summary>
	/// print all volunteers who helped this client
	/// </summary>
	void listOfVolunteers(Client c)
	{
		cout << "The volunteers that helped to client " << c.phone << ":  ";
		int x = clients->search(c.phone);
		if (x == -1) return;
		Client cl = clients->table[x].data;
		for (auto v : cl.volunteers)
			cout << v << " ";
	}

	/// <summary>
	/// print all clients who were helped by this volunteer
	/// </summary>
	void listOfClients(Volunteer v)
	{
		cout << "The clients that were helped by volunteer " << v.name << ":  ";
		for (int i = 0; i < clients->size; i++)
		{
			list<string> l = clients->table[i].data.volunteers;
			for (auto k : l)
				if (k == v.name)
					cout << clients->table[i].data.name << " ";
		}
	}

	/// <summary>
	/// print all volunteers and all clients
	/// </summary>
	void printAll()
	{
		cout << "Volunteers:\n";
		volunteers->print();
		cout << "Clients:\n";
		clients->print();
	}

private:
	/// <summary>
	/// chacking if the list dont have the same string
	/// </summary>
	bool checkIfNotExist(string s, list<string> l)
	{
		for (auto var : l)
			if (var == s)
				return false;
		return true;
	}
};