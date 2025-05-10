#include <iostream>
#include <string>

using namespace std;

class Seat {
	string name;
public:
	Seat() { name = "\t---"; }
	void setName(string name) { this->name = '\t' + name; }
	string getName() { return name; }
};

class Booking {
	Seat* s;
	string time;
public:
	Booking();
	~Booking();
	void setTime(string time) { this->time = time; }
	void setSeat(int seatN, string name) { s[seatN - 1].setName(name); }
	void cancleSeat(int seatN, string name);
	void show();
};
Booking::Booking() {
	s = new Seat[8];
	time = "00��";
}
Booking::~Booking() {
	delete[]s;
}
void Booking::cancleSeat(int seatN, string name) {
	if (s[seatN - 1].getName() == '\t' + name)
		s[seatN - 1].setName("---");
	else
		cout << "���� ������ �ٽ� Ȯ���ϼ���.\n";
}
void Booking::show() {
	cout << time << ':';
	for (int i = 0; i < 8; i++)
		cout << s[i].getName();
	cout << '\n';
}

class Airport {
	Booking* b;
public:
	Airport();
	~Airport();
	void run();
};

Airport::Airport() {
	b = new Booking[3];
	b[0].setTime("07��");
	b[1].setTime("12��");
	b[2].setTime("17��");
	cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****\n\n";
}
Airport::~Airport() {
	delete[]b;
}
void Airport::run() {
	while (true) {
		cout << "\n����:1, ���:2, ����:3, ������:4 >> ";
		int num = 0;
		cin >> num;
		if (num == 4) break;
		if (num == 1 || num == 2) {
			int num2;
			cout << "07��:1, 12��:2, 17��:3 >> ";
			cin >> num2;
			b[num2 - 1].show();
			cout << "�¼� ��ȣ >> ";
			int seatN;
			cin >> seatN;
			cout << "�̸� �Է� >> ";
			string name;
			cin >> name;
			if (num == 1)
				b[num2 - 1].setSeat(seatN, name);
			else if (num == 2)
				b[num2 - 1].cancleSeat(seatN, name);
		}
		else if (num == 3) {
			b[0].show();
			b[1].show();
			b[2].show();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Airport Hansung;
	Hansung.run();
}