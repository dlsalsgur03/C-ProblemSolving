#include <iostream>
#include <string>

using namespace std;

int big(int a, int b, int c = 100);

int big(int a, int b, int c) {
	if (a > b && a < c) return a;
	else if (a > b && a > c) return c;
	else if (a < b && b < c) return b;
	else if (a < b && b > c) return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << '\n';
}