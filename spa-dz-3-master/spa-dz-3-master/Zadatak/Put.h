#pragma once
#include<iostream>

using namespace std;

struct Tocka
{
	int x;
	int y;
};

class Put
{
private:
	static const unsigned int REDAKA = 20;
	static const unsigned int STUPACA = 40;
	Tocka _trenutna_lokacija;
	Tocka _pocetna_lokacija;
	Tocka _zavrsna_lokacija;
	char _polje[20][40];
	bool unesi_tocke();
	void postavi_polje();
	bool ispravna_tocka(Tocka tocka);

public:
	Put();
	void crtaj();
	bool ima_dalje();
};

