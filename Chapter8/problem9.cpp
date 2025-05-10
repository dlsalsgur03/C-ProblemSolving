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
	time = "00시";
}
Booking::~Booking() {
	delete[]s;
}
void Booking::cancleSeat(int seatN, string name) {
	if (s[seatN - 1].getName() == '\t' + name)
		s[seatN - 1].setName("---");
	else
		cout << "예약 정보를 다시 확인하세요.\n";
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
	b[0].setTime("07시");
	b[1].setTime("12시");
	b[2].setTime("17시");
	cout << "***** 한성항공에 오신것을 환영합니다 *****\n\n";
}
Airport::~Airport() {
	delete[]b;
}
void Airport::run() {
	while (true) {
		cout << "\n예약:1, 취소:2, 보기:3, 끝내기:4 >> ";
		int num = 0;
		cin >> num;
		if (num == 4) break;
		if (num == 1 || num == 2) {
			int num2;
			cout << "07시:1, 12시:2, 17시:3 >> ";
			cin >> num2;
			b[num2 - 1].show();
			cout << "좌석 번호 >> ";
			int seatN;
			cin >> seatN;
			cout << "이름 입력 >> ";
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