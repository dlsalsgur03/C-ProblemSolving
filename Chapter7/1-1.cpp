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
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	Book& operator+= (int price);
	Book& operator-= (int price);
};

Book& Book::operator+= (int price) {
	this->price += price;
	return *this;
}
Book& Book::operator-= (int price) {
	this->price -= price;
	return *this;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Book a("청춘", 20000, 500), b("고급 C++", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}