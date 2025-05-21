#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Nation {
	string country;
	string capital;
public:
	Nation(string country, string capital) {
		this->country = country;
		this->capital = capital;
	}
	string getNation() {
		return country;
	}
	string getCapital() {
		return capital;
	}
};

class Game {
	vector<Nation> g;
public:
	Game() {
		srand((unsigned)time(0));
	}
	bool isInVector(string country) {
		for (int i = 0; i < g.size(); i++) {
			if (g.at(i).getNation() == country) return true;
		}
		return false;
	}
	void run();
};

void Game::run() {
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****\n";
	while (true) {
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "현재 " << g.size() << "개의 나라가 입력되어 있습니다.\n";
			cout << "나라와 수도를 입력하세요(no no 이면 입력 종료)\n";
			string country, capital;
			while (true) {
				cout << g.size() << ">>";
				cin >> country >> capital;
				if (country == "no" && capital == "no") break;
				if (isInVector(country)) {
					cout << "already exists !!\n";
					continue;
				}
				else {
					Nation tmp(country, capital);
					g.push_back(tmp);
				}
			}
		}
		else if (n == 2) {
			while (true) {
				int randNum = rand() % g.size();
				cout << g.at(randNum).getNation() << "의 수도는? ";
				string answer;
				cin >> answer;
				if (answer == "exit")break;
				else if (answer == g.at(randNum).getCapital()) cout << "Correct !!\n";
				else cout << "NO !!\n";
			}
		}
		else if (n == 3) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Game g;
	g.run();
}