#include <iostream>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++) {
		cin >> p[i];
	}
}
void Sample::write() {
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << "\n";
}
int Sample::big() {
	int max = -999999;
	for (int i = 0; i < size; i++) {
		if (p[i] > max) max = p[i];
	}
	return max;
}

Sample::~Sample() { delete[]p; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << "\n";
}
