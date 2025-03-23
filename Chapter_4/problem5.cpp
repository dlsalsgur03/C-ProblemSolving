#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	srand((unsigned)time(0));

	string s;
	while (true) {
		cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)\n>> ";
		getline(cin, s);
		if (s == "exit") break;
		int n = rand() % (s.length());
		s[n] = 'a' + rand() % 26;
		cout << s << "\n";
	}
}
