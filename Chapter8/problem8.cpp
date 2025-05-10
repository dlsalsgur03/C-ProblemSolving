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
		cout << "����Ʈ�Ͽ����ϴ�.\n";
	}
	else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
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
		cout << "����Ʈ�Ͽ����ϴ�.\n";
	}
	else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	InkJet* ink = new InkJet("Officejet V40", "HP", 5, 10);
	Laser* laser = new Laser("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����.\n";
	cout << "��ũ�� : " << ink->getModel() << ", " << ink->getManufac() << ", ���� ���� " << ink->getAvailCnt() << "��, ���� ��ũ " << ink->getAvailInk() << '\n';
	cout << "������ : " << laser->getModel() << ", " << laser->getManufac() << ", ���� ���� " << laser->getAvailCnt() << "��, ���� ��� " << laser->getAvailToner() << "\n\n";

	int printNum, pages;
	string gyesok = "y";
	while (gyesok == "y") {
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է� >> ";
		cin >> printNum >> pages;
		if (printNum == 1)
			ink->printInkJet(pages);
		else
			laser->printLaser(pages);
		cout << "��ũ�� : " << ink->getModel() << ", " << ink->getManufac() << ", ���� ���� " << ink->getAvailCnt() << "��, ���� ��ũ " << ink->getAvailInk() << '\n';
		cout << "������ : " << laser->getModel() << ", " << laser->getManufac() << ", ���� ���� " << laser->getAvailCnt() << "��, ���� ��� " << laser->getAvailToner() << '\n';
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>>";
		cin >> gyesok;
		cout << '\n';
	}
}