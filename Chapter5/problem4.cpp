#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) return true;
	else if (a > b) 
		big = a;
	
	else 
		big = b;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << "두 수를 입력하시오 >> ";
	int a, b;
	cin >> a >> b;
	int big;
	if (bigger(a, b, big)) { cout << "둘이 같습니다.\n"; }
	else {
		cout << "더 큰 수는 " << big;
	}
}
