#include <iostream>
#include <string>

using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�.\n";
}
void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class ForLoopAdder : public LoopAdder {
protected:
	virtual int calculate() {
		int tmp = 0;
		for (int i = getX(); i <= getY(); i++) {
			tmp += i;
		}
		return tmp;
	}
public:
	ForLoopAdder(string name = "") : LoopAdder(name) {}
};

class WhileLoopAdder : public LoopAdder {
protected:
	virtual int calculate() {
		int i = getX(), tmp = 0;
		while (i <= getY()) {
			tmp += i;
			i++;
		}
		return tmp;
	}
public:
	WhileLoopAdder(string name = "") : LoopAdder(name) {}
};

class DoWhileLoopAdder : public LoopAdder {
protected:
	virtual int calculate() {
		int i = getX(), tmp = 0;
		do {
			tmp += i;
			i++;
		} while (i <= getY());
		return tmp;
	}
public:
	DoWhileLoopAdder(string name = "") : LoopAdder(name) {}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ForLoopAdder forloop("For Loop");
	forloop.run();

	WhileLoopAdder whileloop("While Loop");
	DoWhileLoopAdder dowhileloop("Do while Loop");

	whileloop.run();
	dowhileloop.run();
}