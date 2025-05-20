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
		if (availCnt < pages) cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
		else if (availInk < pages) cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
		else {
			printedCnt += pages;
			availCnt -= pages;
			availInk -= pages;
			cout << "����Ʈ�Ͽ����ϴ�.\n";
		}
	}
	virtual void show() { cout << model << ", " << manufac << ", ���� ���� " << availCnt << "��, ���� ��ũ " << availInk << '\n'; }
};
class LaserPrinter : public Printer {
	int availToner;
public:
	LaserPrinter(string model, string manufac, int insertedPaper, int insertedToner) : Printer(model, manufac, insertedPaper) { availToner = insertedToner; }
	virtual void print(int pages) {
		if (availCnt < pages)
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
		else if (availToner < 1)
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
		else {
			printedCnt += pages;
			availCnt -= pages;
			availToner -= 1;
			cout << "����Ʈ�Ͽ����ϴ�.\n";
		}
	}
	virtual void show() { cout << model << ", " << manufac << ", ���� ���� " << availCnt << "��, ���� ��ũ " << availToner << '\n'; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	InkJetPrinter ink("Officejet V40", "HP", 5, 10);
	LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����.\n";
	cout << "��ũ�� : "; ink.show();
	cout << "������ : "; laser.show();

	char yon = 'y';
	while (yon != 'n') {
		cout << "\n������(1:��ũ��, 2:������)�� �ż� �Է� >> ";
		int printer, pages;
		cin >> printer >> pages;
		if (printer == 1) ink.print(pages);
		else laser.print(pages);
		ink.show(); laser.show();
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n) >> ";
		cin >> yon;
	}
}