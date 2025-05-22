#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 0;
	char ch;
	while ((ch = cin.get()) != '\n') {
		if (ch == ' ') cnt++;
	}
	cout << "공백의 개수 = " << cnt << endl;
}