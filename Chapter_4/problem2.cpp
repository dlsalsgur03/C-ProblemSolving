#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "정수 5개 입력>> ";
	int* arr = new int[5];
	float aver = 0.0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		aver += arr[i];
	}
	cout << "평균 " << aver/5 << "\n";

	delete[]arr;
}
