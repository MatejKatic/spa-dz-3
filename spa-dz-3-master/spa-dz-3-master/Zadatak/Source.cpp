#include <iostream>
#include<Windows.h>
#include"Put.h"

using namespace std;

int main() {
	
	Put put;
	do {
		system("cls");
		put.crtaj();
		Sleep(100);
	} while (put.ima_dalje());

	return 0;
}