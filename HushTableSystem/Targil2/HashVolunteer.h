#pragma once
#include"Hash.h"
#include"Volanteer.h"
#include<iostream>
#include<string>
using namespace std;

class HashVolunteer : public Hash<Volunteer, string>
{
public:
	HashVolunteer(int num) : Hash(num) {}
	virtual int h1(string s) override;
	virtual int h2(string s) override;
};

/// <summary>
/// a hash function that summarize all letters in the name (ascii value) and return the result mod table's size.
/// </summary>
int HashVolunteer::h1(string s)
{
	int a = 0;
	for (int i = 0; i < s.size(); i++) a += s[i];
	return a % size;
}

/// <summary>
/// a hash function that summarize all letters in the name (ascii value), do some calculations and return the result mod table's size.
/// </summary>
int HashVolunteer::h2(string s)
{
	int a = 0;
	for (int i = 0; i < s.size(); i++) a += s[i];
	a = (a % (a/11)) * 17;
	return a % size;
}
