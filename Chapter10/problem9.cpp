#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> a;
	int n;
	double sum = 0;;
	while (true) {
		cout << "정수를 입력하세요(0을 입력하면 종료)>> ";
		cin >> n;
		if (n == 0) break;
		sum += n;
		a.push_back(n);
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << ' ';
		}
		cout << "\n평균 = " << sum / a.size() << '\n';
	}
}