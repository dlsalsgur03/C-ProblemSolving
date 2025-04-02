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

	cout << "Up & Down 게임을 시작합니다.\n";

	Person p[2];
	p[0].setName("김인수");
	p[1].setName("오은경");

	int num = -1;
	int i = 0;
	while (num != n) {
		cout << "답은 " << left << "과 " << right << "사이에 있습니다.\n";
		cout << p[i % 2].getName() << " >> ";
		cin >> num;
		if (num < n && num > left) left = num;
		else if (num > n && num < right) right = num;
		i++;
	}
	cout << p[(i - 1) % 2].getName() << "(이)가 이겼습니다!!\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	srand((unsigned)time(0));
	UpAndDowngame::run();
}