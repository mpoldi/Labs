#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;
int main() {
	int n; // Размерность массива
	cout << "Number 1, var A\n";
	cout << "Enter size of the list\n";
	cin >> n;
	int* M = new int[n]; // Объявление массива
	cout << "Fill the list\n";
	for (int i = 0; i < n; i++) {
		cin >> M[i];
	}
	for (int i = 0; i < n; i++) { // Вывод массива
		cout << M[i] << " ";
	}
	cout << "\nAdress of the beginning: " << &M[0];
	for (int i = 1; i < n; i++) {
		cout << "\n" << &M[i];
	}
	cout << "\nElements of the list are located 4 blocks away from each other";
	delete[] M;
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}
