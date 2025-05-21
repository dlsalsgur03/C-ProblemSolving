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
	cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****\n";
	while (true) {
		cout << "���� �Է�: 1, ����: 2, ����: 3 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "���� " << g.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�.\n";
			cout << "����� ������ �Է��ϼ���(no no �̸� �Է� ����)\n";
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
				cout << g.at(randNum).getNation() << "�� ������? ";
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