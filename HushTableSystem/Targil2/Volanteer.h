#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Volunteer
{
public:
	string name;
	string address;
	string phone;
	Volunteer() {}
	Volunteer(string myName, string myAddress, string myPhone)
		: name(myName), address(myAddress), phone(myPhone) {}
	~Volunteer() {}

	bool operator==(const Volunteer& volun) { return name == volun.name ? true : false; }
	Volunteer& operator=(const Volunteer& volun)
	{
		name = volun.name;
		address = volun.address;
		phone = volun.phone;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Volunteer& volun);
	friend istream& operator>>(istream& is, Volunteer& volun);
};