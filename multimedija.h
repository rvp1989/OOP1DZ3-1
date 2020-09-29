#pragma once
#include<iostream>
#include<string>
#include"greske.h"
using namespace std;

class Multimedija
{
protected:
	string ime;
	int bajtovi;
public:
	Multimedija(string i) :ime(i) {}
	virtual int dohvVelicinuMul()const { return bajtovi; }
	virtual string opis()const = 0;
	friend ostream& operator<<(ostream& it, const Multimedija& m)
	{
		return it << m.ime << ":" << m.opis();
	}
};