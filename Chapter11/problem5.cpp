#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string cmd;
	cout << "getline(istream&, string)���� ���ڿ��� �н��ϴ�." << endl;
	while (true) {
		cout << "�����Ϸ��� exit�� �Է��ϼ��� >> ";
		getline(cin, cmd);
		if (cmd == "exit") {
			cout << "���α׷��� �����մϴ�....";
			break;
		}
	}
}