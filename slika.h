#pragma once
#include<iostream>
#include<string>
#include"greske.h"
#include"multimedija.h"
#
using namespace std;


class Slika :public Multimedija
{
	int visina;
	int sirina;
	string opis;
public:
	Slika(string ii, int v, int s) :Multimedija(ii)
	{
		visina = v;
		sirina = s;
		opis = "[" + to_string(sirina) + "x" + to_string(visina) + "->" + to_string(velicinaSlike()) + "]";
	}
	int dohvVelicinuPiksela()const { return bajtovi; }
	int velicinaSlike()const
	{
		return sirina * visina * dohvVelicinuPiksela();
	}
	string  dohvOpis()const { return opis; }

};
