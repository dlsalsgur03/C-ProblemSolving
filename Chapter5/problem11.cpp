// 소문제 1, 2, 3은 오류가 발생해서 못함;;

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(const string title, int price);
	~Book();
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << '\n'; }
};

Book::Book(const string title, int price) {
	this->title = title;
	this->price = price;
}
Book::~Book() { }
void Book::set(string title, int price) {
	this->title = title;
	this->price = price;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}