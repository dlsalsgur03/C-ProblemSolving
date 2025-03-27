// �ҹ��� 1, 2, 3�� ������ �߻��ؼ� ����;;

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
	void show() { cout << title << ' ' << price << "��" << '\n'; }
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

	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}