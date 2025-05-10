#include <iostream>
#include <string>

using namespace std;

class Printer {
	string model;
	string manufac;
	int prntCnt;
	int availCnt;
public:
	Printer(string model, string manufac, int availCnt) {
		this->model = model; this->manufac = manufac; this->availCnt = availCnt; prntCnt = 0;
	}
	string getModel() { return model; }
	string getManufac() { return manufac; }
	int getAvailCnt() { return availCnt; }
	bool print(int pages) {
		if (pages <= availCnt) {
			availCnt -= pages;
			prntCnt += pages;
			return true;
		}
		else return false;
	}
};

class InkJet : public Printer {
	int availInk;
public:
	InkJet(string model, string manufac, int availCnt, int availInk) : Printer(model, manufac, availCnt) {
		this->availInk = availInk;
	}
	int getAvailInk() { return availInk; }
	void printInkJet(int pages);
};

void InkJet::printInkJet(int pages) {
	if (print(pages) && pages <= availInk) {
		availInk -= pages;
		cout << "프린트하였습니다.\n";
	}
	else cout << "용지가 부족하여 프린트할 수 없습니다.\n";
}

class Laser : public Printer {
	int availToner;
public:
	Laser(string model, string manufac, int availCnt, int availToner) : Printer(model, manufac, availCnt) {
		this->availToner = availToner;
	}
	int getAvailToner() { return availToner; }
	void printLaser(int pages);
};

void Laser::printLaser(int pages) {
	if (print(pages) && pages <= availToner) {
		availToner -= 1;
		cout << "프린트하였습니다.\n";
	}
	else cout << "용지가 부족하여 프린트할 수 없습니다.\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	InkJet* ink = new InkJet("Officejet V40", "HP", 5, 10);
	Laser* laser = new Laser("SCX-6x45", "삼성전자", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다.\n";
	cout << "잉크젯 : " << ink->getModel() << ", " << ink->getManufac() << ", 남은 종이 " << ink->getAvailCnt() << "장, 남은 잉크 " << ink->getAvailInk() << '\n';
	cout << "레이저 : " << laser->getModel() << ", " << laser->getManufac() << ", 남은 종이 " << laser->getAvailCnt() << "장, 남은 토너 " << laser->getAvailToner() << "\n\n";

	int printNum, pages;
	string gyesok = "y";
	while (gyesok == "y") {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
		cin >> printNum >> pages;
		if (printNum == 1)
			ink->printInkJet(pages);
		else
			laser->printLaser(pages);
		cout << "잉크젯 : " << ink->getModel() << ", " << ink->getManufac() << ", 남은 종이 " << ink->getAvailCnt() << "장, 남은 잉크 " << ink->getAvailInk() << '\n';
		cout << "레이저 : " << laser->getModel() << ", " << laser->getManufac() << ", 남은 종이 " << laser->getAvailCnt() << "장, 남은 토너 " << laser->getAvailToner() << '\n';
		cout << "계속 프린트 하시겠습니까?(y/n)>>";
		cin >> gyesok;
		cout << '\n';
	}
}