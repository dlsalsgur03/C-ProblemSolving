#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
	int year;
	string name;
	string author;
public:
	Book(int year, string name, string author) {
		this->year = year;
		this->name = name;
		this->author = author;
	}
	int getYear() { return year; }
	string getName() { return name; }
	string getAuthor() { return author; }
};

class BookSearcher {
	vector<Book> b;
public:
	void run();
};
void BookSearcher::run() {
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다.\n";
	while (true) {
		cout << "년도>>";
		int year;
		cin >> year;
		cin.ignore();
		if (year == -1) break;
		cout << "책이름>>";
		string name;
		getline(cin, name);
		cout << "작가>>";
		string author;
		getline(cin, author);
		Book tmp(year, name, author);
		b.push_back(tmp);
	}
	cout << "총 입고된 책은 " << b.size() << "권입니다.\n";
	cout << "검색하고자 하는 저자 이름을 입력하세요>>";
	string fName;
	cin >> fName;
	for (int i = 0; i < b.size(); i++) {
		if (b.at(i).getAuthor() == fName) {
			cout << b[i].getYear() << "년도, " << b[i].getName() << ", " << b[i].getAuthor() << '\n';
		}
	}

	cout << "검색하고자 하는 년도를 입력하세요>>";
	int fYear;
	cin >> fYear;
	for (int i = 0; i < b.size(); i++) {
		if (b[i].getYear() == fYear) {
			cout << b[i].getYear() << "년도, " << b[i].getName() << ", " << b[i].getAuthor() << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	BookSearcher s;
	s.run();
}