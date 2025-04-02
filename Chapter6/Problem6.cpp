#include <iostream>

using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* nArr = new int[size * 2];
	for (int i = 0; i < size * 2; i++) {
		if (i < size) nArr[i] = s1[i];
		else if (i >= size) nArr[i] = s2[i - size];
	}
	return nArr;
}
int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* temp = new int[size];
	for (int i = 0; i < size; i++) {
		int flag = 1;
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) {
				flag = 0;
				break;
			}
		}
		if (flag != 0)
			temp[retSize++] = s1[i];
	}
	if (retSize == 0) {
		delete[]temp;
		return NULL;
	}
	int* nArr = new int[retSize];
	for (int i = 0; i < retSize; i++) nArr[i] = temp[i];
	delete[]temp;
	return nArr;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "������ 5�� �Է��϶�. �迭 x�� �����Ѵ�>> ";
	int x[5];
	for (int i = 0; i < 5; i++)
		cin >> x[i];
	cout << "������ 5�� �Է��϶�. �迭 y�� �����Ѵ�>> ";
	int y[5];
	for (int i = 0; i < 5; i++)
		cin >> y[i];
	cout << "��ģ ���� �迭�� ����Ѵ�.\n";
	int* nArr1 = ArrayUtility2::concat(x, y, 5);
	for (int i = 0; i < 10; i++)
		cout << nArr1[i] << ' ';
	cout << '\n';

	int retSize = 0;
	int* nArr2 = ArrayUtility2::remove(x, y, 5, retSize);
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << '\n';
	for (int i = 0; i < retSize; i++)
		cout << nArr2[i] << ' ';
	cout << '\n';
}