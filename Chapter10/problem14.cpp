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
	cout << "***** ��ȣ ���� ���α׷� WHO�� �����մϴ� *****\n";
	while (true) {
		cout << "�Է�:1, ��ȸ:2, ����:3 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "�̸� ��ȣ >> ";
			string name;
			string pw;
			cin >> name >> pw;
			who.insert(make_pair(name, pw));
		}
		else if (n == 2) {
			cout << "�̸�? ";
			string name;
			cin >> name;
			while (true) {
				cout << "��ȣ? ";
				string pw;
				cin >> pw;
				if (who[name] == pw) {
					cout << "���!!\n";
					break;
				}
				else cout << "����~~\n";
			}
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

	WHO wh;
	wh.run();
}