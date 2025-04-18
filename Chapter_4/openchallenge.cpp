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
	cout << "끝말 잇기 게임을 시작합니다.\n";
	cout << "게임에 참가하는 인원은 몇명입니까? ";
	int playerN;
	cin >> playerN;
	p = new Player[playerN];
	for (int i = 0; i < playerN; i++) {
		cout << "참가자의 이름을 입력하세요. 빈칸 없이>> ";
		string name;
		cin >> name;
		p[i].setName(name);
	}
	cout << "시작하는 단어는 아버지입니다.\n";
	int i = 0;
	string w1 = "아버지", w2;
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