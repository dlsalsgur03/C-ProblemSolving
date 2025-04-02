#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


class Person {
	string name;
public:
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};

class UpAndDowngame {
	static int n;
	static int left, right;
public:
	static void run();
};

int UpAndDowngame::n;
int UpAndDowngame::left = 0;
int UpAndDowngame::right = 99;

void UpAndDowngame::run() {
	UpAndDowngame::n = rand() % 100;

	cout << "Up & Down ������ �����մϴ�.\n";

	Person p[2];
	p[0].setName("���μ�");
	p[1].setName("������");

	int num = -1;
	int i = 0;
	while (num != n) {
		cout << "���� " << left << "�� " << right << "���̿� �ֽ��ϴ�.\n";
		cout << p[i % 2].getName() << " >> ";
		cin >> num;
		if (num < n && num > left) left = num;
		else if (num > n && num < right) right = num;
		i++;
	}
	cout << p[(i - 1) % 2].getName() << "(��)�� �̰���ϴ�!!\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	srand((unsigned)time(0));
	UpAndDowngame::run();
}