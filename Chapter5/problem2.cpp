#include <iostream>
using namespace std;

void half(double& n) {
	n /= 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	double n = 20;
	half(n);
	cout << n;
}
