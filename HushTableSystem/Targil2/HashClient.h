#pragma once
#include"Hash.h"
#include"Client.h"
#include<iostream>
#include<string>
using namespace std;

class HashClient : public Hash<Client, int>
{
public:
	HashClient(int num) : Hash<Client, int>(num) {}
	virtual int h1(int phone) override;
	virtual int h2(int phone) override;
};

/// <summary>
/// doing phone number mod size.
/// </summary>
int HashClient::h1(int phone)
{
	return (phone % size);
}

/// <summary>
/// doing some calculations ang teh result mod size.
/// </summary>
int HashClient::h2(int phone)
{

	return (((phone%(phone/11))*15)  % size);
}