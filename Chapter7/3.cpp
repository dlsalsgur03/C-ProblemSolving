#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }
	bool operator! ();
};

bool Book::operator! () {
	if (price == 0) return true;
	else return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Book book("�������", 0, 50);
	if (!book) cout << "��¥��" << '\n';
}