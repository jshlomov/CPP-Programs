#pragma once
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

class Client
{
public:
	string name;
	int phone;
	string address;
	list<string> volunteers;
	Client() { phone = -1; }
	Client(string myName, int  myPhone, string  myAddress) : name(myName), phone(myPhone), address(myAddress) {}
	~Client() {}
	bool operator==(const Client& client) { return phone == client.phone ? true : false; }
	Client& operator=(const Client& client)
	{
		name = client.name;
		phone = client.phone;
		address = client.address;
		volunteers = client.volunteers;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Client& client);
	friend istream& operator>>(istream& is, Client& client);
};