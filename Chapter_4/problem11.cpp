#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume() { size--; }
	int getSize() { return size; }
};

class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	void run();
};

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	}
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << "\n";
}
void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 1) cout << "원료가 부족합니다.\n";
	else {
		cout << "에스프레소 드세요.\n";
		for (int i = 0; i < 2; i++) {
			tong[i].consume();
		}
	}
}
void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 1) cout << "원료가 부족합니다.\n";
	else {
		cout << "아메리카노 드세요.\n";
		for (int i = 0; i < 2; i++) {
			if (i == 1) tong[i].consume();
			tong[i].consume();
		}
	}
}
void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 1) cout << "원료가 부족합니다.\n";
	else {
		cout << "설탕커피 드세요.\n";
		for (int i = 0; i < 3; i++) {
			if (i == 1) tong[i].consume();
			tong[i].consume();
		}
	}
}
void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << "\n";
}
void CoffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****\n";
	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기) >> ";
		int menu_n;
		cin >> menu_n;
		if (menu_n == 1) {
			selectEspresso();
		}
		else if (menu_n == 2) {
			selectAmericano();
		}
		else if (menu_n == 3) {
			selectSugarCoffee();
		}
		else if (menu_n == 4) show();
		else if (menu_n == 5) fill();
		else break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	CoffeeVendingMachine c;
	c.run();
}
