#include <iostream>

using namespace std;

class Statistics {
	int* nArr;
	int size;
	int ind;
public:
	Statistics();
	~Statistics();
	void resize();
	void push(int n);
	bool operator! ();
	Statistics& operator<< (int n);
	void operator~ ();
	int& operator>> (int& n);
};

Statistics::Statistics() {
	size = 0;
	ind = 0;
	nArr = new int[size];
}
Statistics::~Statistics() {
	if (nArr)
		delete[]nArr;
}
void Statistics::resize() {
	size += 1;
	int* tmp = new int[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = nArr[i];
	}
	delete[]nArr;
	nArr = tmp;
}
void Statistics::push(int n) {
	if (ind == size) resize();
	nArr[ind++] = n;
}

bool Statistics::operator! () {
	if (size == 0) return true;
	else return false;
}
Statistics& Statistics::operator<< (int n) {
	push(n);
	return *this;
}
void Statistics::operator~ () {
	for (int i = 0; i < size; i++)
		cout << nArr[i] << ' ';
	cout << '\n';
}
int& Statistics::operator>> (int& n) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += nArr[i];
	}
	n = sum / size;
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << '\n';

	int x[5];
	cout << "5 개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) cin >> x[i];

	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg = 0;
	stat >> avg;
	cout << "avg=" << avg << '\n';
}
