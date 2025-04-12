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
	friend bool operator< (string a, Book op);
};

bool operator< (string a, Book op) {
	if (a < op.title) return true;
	else return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Book a("û��", 20000, 300);
	string b;
	cout << "å �̸��� �Է��ϼ��� >> ";
	getline(cin, b);
	if (b < a)
		cout << '\'' << a.getTitle() << "\'�� \'" << b << "\'���� �ڿ� �ֱ���!" << '\n';
}