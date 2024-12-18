#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <string>
using namespace std;
class Library {
private:
	string author, name, type;
public:
	Library(string uauthor = "Unauthored", string uname = "Unnamed", string utype = "Fiction") { // Конструктор
		setBook(uauthor, uname, utype);
	}
	void setBook(string uauthor, string uname, string utype) {
		author = uauthor;
		name = uname;
		type = utype;
	}
	void getBook() {
		cout << "Author: " << author << "\nName: " << name << "\nType: " << type;
	}
};
int main() {
	string A, N, T; // Добавление пользовательских книг
	Library book1("Engels", "Tech and Such", "Technical");
	book1.getBook();
	cout << "\nAdd a book. Who is the author? What is the name? What is the type?\n";
	cin >> A;
	cin >> N;
	cin >> T;
	Library book2;
	book2.setBook(A, N, T);
	book2.getBook();
	cout << "\n";
	Library book3;
	book3.getBook();
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}
