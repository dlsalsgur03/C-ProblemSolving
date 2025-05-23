#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius;
	string name;
public:
	Circle(int radius = 1, string name = "") { this->radius = radius; this->name = name; }
	friend ostream& operator << (ostream& outs, Circle c);
	friend istream& operator >> (istream& ins, Circle& c);
};

ostream& operator << (ostream& outs, Circle c) {
	outs << "(�������� " << c.radius << "�� " << c.name << ")";
	return outs;
}
istream& operator >> (istream& ins, Circle& c) {
	cout << "������ >> ";
	ins >> c.radius;
	cout << "�̸� >> ";
	ins >> c.name;
	return ins;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}