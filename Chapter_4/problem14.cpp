// 다른 사람의 코드 참고함.
// 아무리 enter를 치면 게임이 시작되게 할 수가 없었음.
// 코드에 추가 설명

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
	string player;
	int card[3];
public:
	Player() { };
	void setName(string name) { player = name; }
	string getName() { return player; }
	bool playGame();
};
bool Player::playGame() {
	for (int i = 0; i < 3; i++) {
		card[i] = rand() % 3;
		cout << "\t" << card[i];
	}
	for (int i = 0; i < 2; i++) {
		if (card[i] != card[i + 1])
			return false;
	}
	return true;
}

class GamblingGame {
	Player p[2];
	bool isGameEnd = false;
public:
	GamblingGame();
	void play();
};
GamblingGame::GamblingGame() {
	cout << "***** 갬블링 게임을 시작합니다. *****\n";
	string p1, p2;
	cout << "첫번째 선수 이름>> ";
	cin >> p1;
	p[0].setName(p1);
	cout << "두번째 선수 이름>> ";
	cin >> p2;
	p[1].setName(p2);
	cin.get(); // 여기가 그 차이점이지 않을까 싶음; Enter를 입력하기 전에 한 번 게임이 자동으로 실행 되는 것을 막아줌;
}
void GamblingGame::play() {
	int i = 0;
	while (!isGameEnd) {
		cout << p[i % 2].getName() << ":<Enter>";
		cin.get();
		if (p[i % 2].playGame()) {
			cout << "\t" << p[i % 2].getName() << "님 승리!!\n";
			isGameEnd = true;
		}
		else cout << "\t아쉽군요!!\n";
		i++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	GamblingGame game;
	game.play();
}
