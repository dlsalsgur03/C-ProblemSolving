#include <iostream>
#include <string>
#include <map>

using namespace std;

class WHO {
	map<string, string> who;
public:
	void run();
};

void WHO::run() {
	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****\n";
	while (true) {
		cout << "입력:1, 조회:2, 종료:3 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "이름 암호 >> ";
			string name;
			string pw;
			cin >> name >> pw;
			who.insert(make_pair(name, pw));
		}
		else if (n == 2) {
			cout << "이름? ";
			string name;
			cin >> name;
			while (true) {
				cout << "암호? ";
				string pw;
				cin >> pw;
				if (who[name] == pw) {
					cout << "통과!!\n";
					break;
				}
				else cout << "실패~~\n";
			}
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

	WHO wh;
	wh.run();
}