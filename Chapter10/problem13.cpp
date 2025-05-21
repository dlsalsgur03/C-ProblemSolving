#include <iostream>
#include <string>
#include <map>

using namespace std;

class ScoreManager {
	map<string, int> scm;
public:
	void run();
};

void ScoreManager::run() {
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****\n";
	while (true) {
		cout << "입력:1, 조회:2, 종료:3 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "이름과 점수 >> ";
			string name;
			int score;
			cin >> name >> score;
			scm.insert(make_pair(name, score));
		}
		else if (n == 2) {
			cout << "이름 >> ";
			string name;
			cin >> name;
			cout << name << "의 점수는 " << scm[name] << '\n';
		}
		else if (n == 3) {
			cout << "프로그램을 종료합니다...\n";
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ScoreManager sm;
	sm.run();
}