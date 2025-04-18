#include <iostream>
#include <string>

using namespace std;

class Player {
	string name;
public:
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};

class WordGame {
	Player* p;
public:
	void swap(string& w1, string& w2);
	void run();
};

void WordGame::run() {
	cout << "���� �ձ� ������ �����մϴ�.\n";
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�? ";
	int playerN;
	cin >> playerN;
	p = new Player[playerN];
	for (int i = 0; i < playerN; i++) {
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ ����>> ";
		string name;
		cin >> name;
		p[i].setName(name);
	}
	cout << "�����ϴ� �ܾ�� �ƹ����Դϴ�.\n";
	int i = 0;
	string w1 = "�ƹ���", w2;
	while (true) {
		cout << p[i % playerN].getName() << ">> ";
		cin >> w2;
		if (w1[w1.length() - 2] == w2[0] && w1[w1.length() - 1] == w2[1]) {
			w1 = w2;
			i++;
		}
		else {
			delete[]p;
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	WordGame game;
	game.run();
}