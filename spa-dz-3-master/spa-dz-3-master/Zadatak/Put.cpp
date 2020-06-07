#include "Put.h"
using namespace std;


Put::Put() 
{
	cout << "Unesite tocke A i B:" << endl;

	while (!unesi_tocke()) {
		cout << "Unos izvan dozvoljenog raspona! Molim Vas, unesite ponovno:" << endl;
	}

	postavi_polje();
}

bool Put::unesi_tocke() 
{
	cout << "Redak za tocku A (Raspon: 1-" << this->REDAKA << "): ";
	cin >> _pocetna_lokacija.x;
	cout << "Stupac za tocku A (Raspon: 1-" << this->STUPACA << "): ";
	cin >> _pocetna_lokacija.y;

	cout << "Redak za tocku B (Raspon: 1-" << this->REDAKA << "): ";
	cin >> _zavrsna_lokacija.x;
	cout << "Stupac za tocku B (Raspon: 1-" << this->STUPACA << "): ";
	cin >> _zavrsna_lokacija.y;

	return ispravna_tocka(_pocetna_lokacija) && ispravna_tocka(_zavrsna_lokacija);
}

void Put::postavi_polje()
{
	_pocetna_lokacija.x--;
	_pocetna_lokacija.y--;
	_zavrsna_lokacija.x--;
	_zavrsna_lokacija.y--;

	this->_trenutna_lokacija.x = _pocetna_lokacija.x;
	this->_trenutna_lokacija.y = _pocetna_lokacija.y;

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (i == _pocetna_lokacija.x && j == _pocetna_lokacija.y)
			{
				_polje[i][j] = 'A';
			}
			else if (i == _zavrsna_lokacija.x && j == _zavrsna_lokacija.y)
			{
				_polje[i][j] = 'B';
			}
			else
			{
				_polje[i][j] = '-';
			}
			
		}
	}

}

bool Put::ispravna_tocka(Tocka tocka)
{
	return !(tocka.x < 1 || tocka.x > REDAKA || tocka.y < 1 || tocka.y > STUPACA);
}

void Put::crtaj() 
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_trenutna_lokacija.x == i && _trenutna_lokacija.y == j)
			{
				cout << 'x';
			}
			else
			{
				cout << _polje[i][j];
			}
		}
		cout << endl;
	}
}


bool Put::ima_dalje() 
{
	if (_zavrsna_lokacija.x == _trenutna_lokacija.x && _zavrsna_lokacija.y == _trenutna_lokacija.y)
	{
		return false;
	}

	if (_pocetna_lokacija.x <= _zavrsna_lokacija.x)
	{
		if (this->_trenutna_lokacija.y < this->_zavrsna_lokacija.y)
		{
			_trenutna_lokacija.y ++;
		}
		else
		{
			_trenutna_lokacija.x ++;
		}
	}
	else
	{
		if (this->_trenutna_lokacija.y > this->_zavrsna_lokacija.y)
		{
			_trenutna_lokacija.y --;
		}
		else
		{
			_trenutna_lokacija.x --;
		}
	}
	return true;
}