#pragma once
#include<iostream>
#include<string>
using namespace std;

class Gnijedobarformat
{
	friend ostream& operator<<(ostream& it, const Gnijedobarformat&)
	{
		return it << "***GRESKA:NIJE DOBAR FORMAT LOZINKE***";
	}
};

class GNepoklapa
{
	friend ostream& operator<<(ostream& it, const GNepoklapa&)
	{
		return it << "***GRESKA:NE POKLAPA SE SA TEKUCOM LOZINKOM***";
	}
};

class Gnepostoji
{
	friend ostream& operator<<(ostream& it, const Gnepostoji&)
	{
		return it << "***GRESKA:NE POSTOJI PODATAK NA OVOJ POZICIJI***";
	}
};

class GnepostojiKorinsik
{
	friend ostream& operator<<(ostream& it, const Gnepostoji&)
	{
		return it << "***GRESKA:NE POSTOJI KORISNIK U EVIDENCIJI***";
	}
};