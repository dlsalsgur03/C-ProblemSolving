#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() { this->name = "?"; }
	Person(string name) { this->name = name; }
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};

class Family {
	Person* p;
	string familyName;
	int size;
public:
	Family(string name, int size);
	void setName(int ind, string name);
	void show();
	~Family();
};

Family::Family(string name, int size) {
	this->familyName = name;
	this->size = size;
	this->p = new Person[size];
}

void Family::setName(int ind, string name) {
	this->p[ind].setName(name);
}

void Family::show() {
	cout << familyName << "가족은 다음과 같이 " << size << "명 입니다.\n";
	for (int i = 0; i < this->size; i++) {
		cout << p[i].getName() << "\t";
	}
	cout << "\n";
}

Family::~Family() {
	delete []p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	Family* simpson = new Family("Simpson", 4);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->setName(3, "Lisa Simpson");
	simpson->show();
	delete simpson;
}
