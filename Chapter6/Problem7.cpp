#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};

int Random::nextInt(int min, int max) {
	int n = rand() % (max - min + 1) + min;
	return n;
}
char Random::nextAlphabet() {
	char n = rand() % (122 - 65 + 1) + 65;
	while (n > 90 && n < 97)
		n = rand() % (122 - 65 + 1) + 65;
	return n;
}
double Random::nextDouble() {
	double n = (double)Random::nextInt() / 32767;
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Random::seed();
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다.\n";
	for (int i = 0; i < 10; i++)
		cout << Random::nextInt(1, 100) << ' ';
	cout << '\n';

	cout << "알파벳을 랜덤하게 10개를 출력합니다.\n";
	for (int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << ' ';
	cout << '\n';

	cout << "랜덤한 실수를 10개 출력합니다.\n";
	for (int i = 0; i < 10; i++) {
		if (i == 5) cout << '\n';
		cout << Random::nextDouble() << ' ';
	}
	cout << '\n';
}