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
	cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****\n";
	while (true) {
		cout << "�Է�:1, ��ȸ:2, ����:3 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "�̸��� ���� >> ";
			string name;
			int score;
			cin >> name >> score;
			scm.insert(make_pair(name, score));
		}
		else if (n == 2) {
			cout << "�̸� >> ";
			string name;
			cin >> name;
			cout << name << "�� ������ " << scm[name] << '\n';
		}
		else if (n == 3) {
			cout << "���α׷��� �����մϴ�...\n";
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