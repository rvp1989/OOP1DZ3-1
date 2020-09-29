#pragma once
#include<iostream>
#include<string>
#include"greske.h"
#include"korisnik.h"
#include"lista.h"
using namespace std;
class Evidencija

{
	Lista<Korisnik*>korisnici;
	void brisi();
	void pisi(ostream& it)const;
public:
	Evidencija(Lista<Korisnik*> lst) :
		korisnici(lst) {}
	Evidencija(const Evidencija& ev) = delete;
	Evidencija& operator=(const Evidencija& ev) = delete;
	~Evidencija() { brisi(); }
	Evidencija& operator+=(const Korisnik& k);
	Korisnik* operator[](string ime)
	{
		for (int i = 0; i <korisnici.dohvatiBr(); i++)
		{
			Korisnik* korisnik = korisnici[i];
			if (korisnik->dohvIme() == ime)
				return korisnik;
		}
		throw GnepostojiKorinsik();
	}
	void operator()(string ime)
	{
		for (int i = 0; i < korisnici.dohvatiBr(); i++)
		{
			Korisnik* korisnik = korisnici[i];
			if (korisnik->dohvIme() == ime)
			{
				korisnici(i);
				return;
			}
		}
		throw GnepostojiKorinsik();
	}

	void promenaSifre(string ime, string old, string neww)
	{
		for (int i = 0; i < korisnici.dohvatiBr(); i++)
		{
			Korisnik* korisnik = korisnici[i];
			if (korisnik->dohvIme() == ime)
			{
				korisnik->promenaPassworda(old, neww);
				return;
			}
		}
		throw GnepostojiKorinsik();
	}
	friend ostream& operator<<(ostream& it, const Evidencija& e)
	{
		e.pisi();
		retrun it;
	}

};