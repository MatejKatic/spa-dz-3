#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;



void input(int& StGoreac_A, int& Redak_A, int& StGoreac_B, int& Redak_B, int& Redak_Zida, int& StGoreac_Zida, int& Velicina_Zida)
{
	do
	{
		cout << "A redak (1-20): ";
		cin >> Redak_A;

		cout << "A stGoreac (1-40): ";
		cin >> StGoreac_A;

		cout << "B redak (1-20): ";
		cin >> Redak_B;

		cout << "B stGoreac (1-40): ";
		cin >> StGoreac_B;


		cout << "Unesite velicinu zida (nemoze biti veca od 20): ";
		cin >> Velicina_Zida;
		cout << endl;
		cout << "PAZITE!! StGoreac zida ne moze biti vece od 41 i Redak zida se mora tocno procijeniti s velicinom zida" << endl;
		cout << endl;
		cout << "Unesite Redak (1-20) zida: ";
		cin >> Redak_Zida;

		cout << "Unesite StGoreac (1-40) zida: ";
		cin >> StGoreac_Zida;

		system("cls");
	} while (StGoreac_A < 1 || StGoreac_A > 40 || Redak_A < 1 || Redak_A > 20 || StGoreac_B < 1 || StGoreac_B > 40 || Redak_B < 1 || Redak_B > 20 || (StGoreac_A == StGoreac_B && Redak_A == Redak_B) || (Redak_A >= Redak_Zida && Redak_A <= (Redak_Zida + Velicina_Zida) && StGoreac_A == StGoreac_Zida) || Redak_Zida + Velicina_Zida > 21 || (Redak_B >= Redak_Zida && Redak_B <= (Redak_Zida + Velicina_Zida) && StGoreac_B == StGoreac_Zida));
}

void stRedak_At(vector<vector<char>>& mapa, int& StGoreac_A, int& Redak_A, int& StGoreac_B, int& Redak_B, int StGoreac_Zida, int Redak_Zida, int Velicina_Zida)
{
	for (int i = 0; i < 20; i++)
	{
		vector<char> znak;
		for (int j = 0; j < 40; j++)
		{
			if (j == (StGoreac_Zida - 1) && i == (Redak_Zida - 1) )
			{
				if (Velicina_Zida > 1)
				{
					Redak_Zida++;
					Velicina_Zida--;
				}
				cout << "*";
				znak.push_back('*');
			}

			else if (j == (StGoreac_A - 1) && i == (Redak_A - 1))
			{
				cout << "A";
				znak.push_back('A');
			}

			else if (j == (StGoreac_B - 1) && i == (Redak_B - 1))
			{
				cout << "B";
				znak.push_back('B');
			}

			else
			{
				cout << "-";
				znak.push_back('-');
			}
		}
		cout << endl;
		mapa.push_back(znak);
	}
}

void check(vector<vector<char>>& mapa, int& StGoreac_A, int& Redak_A, int& StGoreac_B, int& Redak_B, int StGoreac_Zida, int Redak_Zida, int Velicina_Zida, int X_A, int X_B, bool& Gore, bool& CanGore, bool& CanDown)
{
	int CounterGore = 0;
	int CounterDown = 0;
	int tempX_A = X_A;
	int tempX_B = X_B;
	Gore = true;

	if (X_A!=StGoreac_B)
	{
		if(X_A < StGoreac_B || tempX_A < StGoreac_B)
		{
			do
			{
						if ((X_A + 1) == StGoreac_Zida && (X_B >= Redak_Zida && X_B < Redak_Zida + Velicina_Zida))
						{

							if (X_B > 1)
							{
								X_B--;
								CounterGore++;
							}

							else
							{
								CanGore = false;
							}
						}
						else
						{
							X_A++;
							CounterGore++;
						}

			} while (X_A!=StGoreac_B && CanGore == true);

			do
			{
					if ((tempX_A + 1) == StGoreac_Zida && (tempX_B >= Redak_Zida && tempX_B < Redak_Zida + Velicina_Zida))
					{
						if (tempX_B < 20)
						{
							tempX_B++;
							CounterDown++;
						}

						else
						{
							CanDown = false;
						}
					}

					else
					{
						tempX_A++;
						CounterDown++;
					}
			} while (tempX_A < StGoreac_B && CanDown == true);

		}

		else
		{
			do
			{
				if (X_A > StGoreac_B)
				{
					if ((X_A - 1) == StGoreac_Zida && (X_B >= Redak_Zida && X_B <= Redak_Zida + Velicina_Zida))
					{

						if (X_B > 1)
						{
							X_B--;
							CounterGore++;
						}

						else
						{
							CanGore = false;
						}
					}

					else
					{
						X_A--;
						CounterGore++;
					}
				}
			} while (X_A > StGoreac_B && CanGore == true);

			do
			{
					if ((tempX_A - 1) == StGoreac_Zida && (tempX_B >= Redak_Zida && tempX_B < Redak_Zida + Velicina_Zida))
					{
						if (tempX_B < 20)
						{
							tempX_B++;
							CounterDown++;
						}

						else
						{
							CanDown = false;
						}
					}

					else
					{
						tempX_A--;
						CounterDown++;
					}
			} while (tempX_A > StGoreac_B && CanDown == true);
		}
	}

	if (X_B!= Redak_B)
	{
		if (X_B < Redak_B || tempX_B < Redak_B)
		{
			do
			{
				if (CanGore && X_B < Redak_B)
				{
					if (X_B != Redak_B)
					{
						X_B++;
						CounterGore++;
					}
				}

				else if (CanDown && tempX_B < Redak_B)
				{
					if (tempX_B != Redak_B)
					{
						tempX_B++;
						CounterDown++;
					}
				}

				else
				{
					Gore = false;
				}

			} while ((Gore));
		}

		Gore = true;

		if (X_B > Redak_B || tempX_B > Redak_B )
		{
			do
			{
				if (CanGore && X_B > Redak_B)
				{
					if (X_B != Redak_B)
					{
						X_B--;
						CounterGore++;
					}
				}

				else if (CanDown && tempX_B > Redak_B)
				{
					if (tempX_B != Redak_B)
					{
						tempX_B--;
						CounterDown++;
					}
				}

				else
				{
					Gore = false;
				}

			} while ((Gore));
		}
	}


	if (CanGore && CanDown)
	{
		if (CounterGore < CounterDown)
		{
			Gore = true;
		}

		else
		{
			Gore = false;
		}
	}

	else if (CanGore)
	{
		Gore = true;
	}

	else if (CanDown)
	{
		Gore = false;
	}
}

void Goredate(vector<vector<char>>& mapa, int& StGoreac_B, int& Redak_B, int StGoreac_Zida, int Redak_Zida, int Velicina_Zida, bool& Gore, int& X_A, int& X_B)
{
	if (StGoreac_B != X_A)
	{
		if (StGoreac_B > X_A)
		{
			if (mapa[X_B - 1][X_A] == '*')
			{
				if (Gore)
				{
					mapa[X_B - 1][X_A - 1] = 'A';
					mapa[X_B - 2][X_A - 1] = 'x';
					X_B--;
				}

				else
				{
					mapa[X_B - 1][X_A - 1] = 'A';
					mapa[X_B][X_A - 1] = 'x';
					X_B++;
				}

			}

			else
			{
				mapa[X_B - 1][X_A - 1] = 'A';
				mapa[X_B - 1][X_A] = 'x';
				X_A++;
			}
		}

		else
		{
			if (mapa[X_B - 1][X_A - 2] == '*')
			{
				if (Gore)
				{
					mapa[X_B - 1][X_A - 1] = 'A';
					mapa[X_B - 2][X_A - 1] = 'x';
					X_B--;
				}

				else
				{
					mapa[X_B - 1][X_A - 1] = 'A';
					mapa[X_B][X_A - 1] = 'x';
					X_B++;
				}

			}

			else
			{
				mapa[X_B - 1][X_A - 1] = 'A';
				mapa[X_B - 1][X_A - 2] = 'x';
				X_A--;
			}
		}

	}

	else if (Redak_B != X_B)
	{
		if (Redak_B > X_B)
		{
			mapa[X_B - 1][X_A - 1] = 'A';
			mapa[X_B][X_A - 1] = 'x';
			X_B++;

		}

		else
		{
			mapa[X_B - 1][X_A - 1] = 'A';
			mapa[X_B - 2][X_A - 1] = 'x';
			X_B--;
		}
	}

	do
	{
		Sleep(100);
		system("cls");
		if (StGoreac_B != X_A)
		{
			if (StGoreac_B > X_A)
			{
				if (mapa[X_B - 1][X_A] == '*')
				{
					if (Gore)
					{
						mapa[X_B - 1][X_A - 1] = '-';
						mapa[X_B - 2][X_A - 1] = 'x';
						X_B--;
					}

					else
					{
						mapa[X_B - 1][X_A - 1] = '-';
						mapa[X_B][X_A - 1] = 'x';
						X_B++;
					}

				}

				else
				{
					mapa[X_B - 1][X_A - 1] = '-';
					mapa[X_B - 1][X_A] = 'x';
					X_A++;
				}
			}

			else
			{
				if (mapa[X_B - 1][X_A - 2] == '*')
				{
					if (Gore)
					{
						mapa[X_B - 1][X_A - 1] = '-';
						mapa[X_B - 2][X_A - 1] = 'x';
						X_B--;
					}

					else
					{
						mapa[X_B - 1][X_A - 1] = '-';
						mapa[X_B][X_A - 1] = 'x';
						X_B++;
					}

				}

				else
				{
					mapa[X_B - 1][X_A - 1] = '-';
					mapa[X_B - 1][X_A - 2] = 'x';
					X_A--;
				}
			}

		}

		else if (Redak_B != X_B)
		{
			if (Redak_B > X_B)
			{
				mapa[X_B - 1][X_A - 1] = '-';
				mapa[X_B][X_A - 1] = 'x';
				X_B++;

			}

			else
			{
				mapa[X_B - 1][X_A - 1] = '-';
				mapa[X_B - 2][X_A - 1] = 'x';
				X_B--;
			}
		}

		for (int i = 0; i < mapa.size(); i++)
		{
			for (int j = 0; j < mapa[i].size(); j++)
			{
				cout << mapa[i][j];
			}
			cout << endl;
		}

	} while (X_A!= StGoreac_B || X_B!= Redak_B);

}

int main()
{
	vector<vector<char>> mapa;
	int Redak_A;
	int StGoreac_A;
	int Redak_B;
	int StGoreac_B;
	int Redak_Zida;
	int StGoreac_Zida;
	int Velicina_Zida;
	input(StGoreac_A, Redak_A, StGoreac_B, Redak_B, Redak_Zida, StGoreac_Zida, Velicina_Zida);
	int X_A = StGoreac_A;
	int X_B = Redak_A;
	bool Gore;
	bool CanGore = true;
	bool CanDown = true;
	stRedak_At(mapa, StGoreac_A, Redak_A, StGoreac_B, Redak_B, StGoreac_Zida, Redak_Zida, Velicina_Zida);

	check(mapa, StGoreac_A, Redak_A, StGoreac_B, Redak_B, StGoreac_Zida, Redak_Zida, Velicina_Zida, X_A, X_B, Gore, CanGore, CanDown);

	if (!CanGore && !CanDown)
	{
		cout << endl << "Nije moguce doci do B" << endl;
		return 1;
	}

	Goredate(mapa, StGoreac_B, Redak_B, StGoreac_Zida, Redak_Zida, Velicina_Zida, Gore, X_A, X_B);


	return 0;
}