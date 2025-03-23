#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

  // 3-1번
	cout << "문자열 입력>> ";
	string s1;
	getline(cin, s1);
	int cnt = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1.at(i) == 'a') cnt++;
	}
	cout << "문자 a는 " << cnt << "개 있습니다." << "\n";

  // 3-2번
  cout << "문자열 입력>> ";
  string s2;
  getline(cin, s2);
  int startIndex = 0, cnt = 0;
  while (true) {
  	int fIndex = s2.find('a', startIndex);
  	if (fIndex == -1) break;
  	else cnt++;
  	startIndex = fIndex + 1;
  }
  cout << "문자 a는 " << cnt << "개 있습니다." << "\n";
}
