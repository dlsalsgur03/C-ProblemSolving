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
	cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�.\n";
	while (true) {
		cout << "�⵵>>";
		int year;
		cin >> year;
		cin.ignore();
		if (year == -1) break;
		cout << "å�̸�>>";
		string name;
		getline(cin, name);
		cout << "�۰�>>";
		string author;
		getline(cin, author);
		Book tmp(year, name, author);
		b.push_back(tmp);
	}
	cout << "�� �԰�� å�� " << b.size() << "���Դϴ�.\n";
	cout << "�˻��ϰ��� �ϴ� ���� �̸��� �Է��ϼ���>>";
	string fName;
	cin >> fName;
	for (int i = 0; i < b.size(); i++) {
		if (b.at(i).getAuthor() == fName) {
			cout << b[i].getYear() << "�⵵, " << b[i].getName() << ", " << b[i].getAuthor() << '\n';
		}
	}

	cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>>";
	int fYear;
	cin >> fYear;
	for (int i = 0; i < b.size(); i++) {
		if (b[i].getYear() == fYear) {
			cout << b[i].getYear() << "�⵵, " << b[i].getName() << ", " << b[i].getAuthor() << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	BookSearcher s;
	s.run();
}