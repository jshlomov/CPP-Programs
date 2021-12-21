#include"Volanteer.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& os, const Volunteer& volun)
{
	os << volun.name << ":";
	os << "Volunteer name= " << volun.name << " address= " << volun.address << " phone= " << volun.phone;
	return os;
}

istream& operator>>(istream& is, Volunteer& volun)
{
	cout << "Enter volunteer name phone address\n";
	is >> volun.name;
	is >> volun.phone;
	is >> volun.address;
	return is;
}