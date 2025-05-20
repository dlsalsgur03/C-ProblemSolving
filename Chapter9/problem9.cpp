#include <iostream>
#include <string>

using namespace std;

class Printer {
protected:
	string model;
	string manufac;
	int printedCnt;
	int availCnt;
public:
	Printer(string model, string manufac, int insertedPaper) { this->model = model; this->manufac = manufac; printedCnt = 0; availCnt = insertedPaper; }
	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

class InkJetPrinter : public Printer {
	int availInk;
public:
	InkJetPrinter(string model, string manufac, int insertedPaper, int insertedInk) : Printer(model, manufac, insertedPaper) { availInk = insertedInk; }
	virtual void print(int pages) {
		if (availCnt < pages) cout << "용지가 부족하여 프린트할 수 없습니다.\n";
		else if (availInk < pages) cout << "잉크가 부족하여 프린트할 수 없습니다.\n";
		else {
			printedCnt += pages;
			availCnt -= pages;
			availInk -= pages;
			cout << "프린트하였습니다.\n";
		}
	}
	virtual void show() { cout << model << ", " << manufac << ", 남은 종이 " << availCnt << "장, 남은 잉크 " << availInk << '\n'; }
};
class LaserPrinter : public Printer {
	int availToner;
public:
	LaserPrinter(string model, string manufac, int insertedPaper, int insertedToner) : Printer(model, manufac, insertedPaper) { availToner = insertedToner; }
	virtual void print(int pages) {
		if (availCnt < pages)
			cout << "용지가 부족하여 프린트할 수 없습니다.\n";
		else if (availToner < 1)
			cout << "잉크가 부족하여 프린트할 수 없습니다.\n";
		else {
			printedCnt += pages;
			availCnt -= pages;
			availToner -= 1;
			cout << "프린트하였습니다.\n";
		}
	}
	virtual void show() { cout << model << ", " << manufac << ", 남은 종이 " << availCnt << "장, 남은 잉크 " << availToner << '\n'; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	InkJetPrinter ink("Officejet V40", "HP", 5, 10);
	LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다.\n";
	cout << "잉크젯 : "; ink.show();
	cout << "레이저 : "; laser.show();

	char yon = 'y';
	while (yon != 'n') {
		cout << "\n프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
		int printer, pages;
		cin >> printer >> pages;
		if (printer == 1) ink.print(pages);
		else laser.print(pages);
		ink.show(); laser.show();
		cout << "계속 프린트 하시겠습니까?(y/n) >> ";
		cin >> yon;
	}
}