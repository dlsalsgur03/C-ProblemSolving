#include <iostream>
#include <string>

using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요 >> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	string src;
	string dest;
	double convert(double src);
	string getSourceString();
	string getDestString();
public:
	WonToDollar(double ratio) : Converter(ratio) { src = "원"; dest = "달러"; }
};

double WonToDollar::convert(double src) {
	double tmp;
	tmp = src / ratio;
	return tmp;
}
string WonToDollar::getSourceString() { return src; }
string WonToDollar::getDestString() { return dest; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	WonToDollar wtd(1010);
	wtd.run();
}