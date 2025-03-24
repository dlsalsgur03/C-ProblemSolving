#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	string getname() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	Person people[3];
	cout << "이름과 전화 번호를 입력해 주세요\n";
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		string name, tel;
		cin >> name >> tel;
		people[i].set(name, tel);
	}
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << people[i].getname() << " ";
	}
	cout << "\n전화번호 검색합니다. 이름을 입력하세요>> ";
	string fname;
	cin >> fname;
	for (int i = 0; i < 3; i++) {
		if (fname == people[i].getname()) {
			cout << people[i].getTel() << "\n";
			break;
		}
	}
}
