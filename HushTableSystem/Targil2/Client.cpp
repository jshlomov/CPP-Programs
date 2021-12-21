#include"Client.h"
#include<iostream>
#include<string>
#include<list>
using namespace std;

ostream& operator<<(ostream& os, const Client& client)
{
	os << client.phone << ":Client name= " << client.name << " phone= " << client.phone;
	os << " address= " << client.address << " helped by= ";
	list<string> l = client.volunteers;
	for (list<string>::iterator it = l.begin(); it != l.end(); it++)
		//for (auto var : client.volunteers)
		os << *it << " ";
	return os;
}

istream& operator>>(istream& is, Client& client)
{
	cout << "please enter name and phone and address of client\n";
	is >> client.name;
	is >> client.phone;
	is >> client.address;
	return is;
}