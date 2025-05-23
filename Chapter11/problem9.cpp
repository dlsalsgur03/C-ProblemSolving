#include <iostream>
#include <string>

using namespace std;

class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend ostream& operator << (ostream& outs, Phone p);
	friend istream& operator >> (istream& ins, Phone& p);
};

ostream& operator << (ostream& outs, Phone p) {
	outs << '(' << p.name << ',' << p.telnum << ',' << p.address << ')';
	return outs;
}
istream& operator >> (istream& ins, Phone& p) {
	cout << "이름:";
	getline(cin, p.name);
	cout << "전화번호:";
	getline(cin, p.telnum);
	cout << "주소:";
	getline(cin, p.address);
	return ins;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}