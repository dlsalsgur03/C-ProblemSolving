#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	while (true) {
		cout << "아래에 한 줄을 입력하세요.(exit을 입력하면 종료합니다)\n>> ";
		getline(cin, s);
		if (s == "exit") break;
		for (int i = s.length()-1; i >= 0; i--) {
			cout << s[i];
		}
		cout << "\n";
	}
}
