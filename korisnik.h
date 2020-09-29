#pragma once
#include<iostream>
#include<string>
#include"greske.h"
using namespace std;

class Korisnik
{
protected:
	string ime;
	string password;
public:
	bool prekratko(const string password);
	bool imaSlovo(const string password);
	bool imaBroj(const string password);
	void promenaPassworda(string stara, string nova);
	Korisnik(string i, const string pas)
	{
		ime = i;
		password = pas;
	}
	string dohvIme()const { return ime; }
	string dohvLozinku(const string& password)
	{
		bool isGood = true;

		if (!prekratko(password) && imaSlovo(password) && imaBroj(password))
		{
			isGood = true;
		}
		else
		{
			throw Gnijedobarformat();
		}
		return password;
	}

	friend bool operator==(const Korisnik& k1, const Korisnik& k2)
	{
		if (k1.ime == k2.ime)
			return true;
	}
protected:
	friend ostream& operator<<(ostream& it, const Korisnik& k)
	{
		return it << k.ime;
	}

};

void Korisnik::promenaPassworda(string s, string n)
{
	password = s;
	s = n;
	n = password;
}

bool Korisnik::prekratko(const string password)
{
	return password.size() < 8 ? true : false;
}

bool Korisnik::imaSlovo(const string password)
{
	for (auto& c : password)
	{
		if (islower(c) || isupper(c))
			return true;
	}
	return false;
}

bool Korisnik::imaBroj(const string password)
{
	for (auto& c : password)
	{
		if (isdigit(c))
			return true;
	}
	return false;
}