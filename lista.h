#pragma once

#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Lista
{
protected:
	struct Elem
	{
		T pod;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr)
			:pod(p), sled(s) {}
	};
	Elem* prvi, * posl,*pret;
	int br;
	mutable Elem* tek;
	void brisi();
public:
	Lista() { prvi = posl = tek = nullptr;br = 0; }
	Lista(const Lista& lst);
	Lista(Lista&& lst)
	{
		prvi = lst.prvi;
		posl = lst.posl;
		br = lst.br;
		lst.prvi = lst.posl = nullptr;
	}
	~Lista() { brisi(); };
	Lista& operator+=(const T& t) {
		posl = (!prvi ? prvi : posl->sled) =
			new Elem(t);
		return *this;
	}
	T& operator[](int i)
	{
		if (i < 0 || i >= br)
			throw Gnepostoji();
		Elem* tek = prvi;
		int n = 0;
		while (!tek)
		{
			if (n == i)
				break;
			++n;
			tek = tek->pod;
		}

	}
	const T& operator[](int i) const
	{
		return const_cast<Lista&>(*this)[i];
	}
	Lista& operator()(int i)const
	{
		Elem* tek = prvi * pret;
		int n = 0;
		while (!tek)
		{
			if (n == i)
				break;
			++n;
			if (tek = prvi)
				pret = prvi;
			else
				pret = pret->sled;
			tek = tek->sled;
		}
		pret->sled = tek->sled;
		delete tek;

	}
	int dohvatiBr()const
	{
		return  br;
	}
};

template<typename T>
void Lista<T>::brisi()
{
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = nullptr;
}


