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
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ��� >> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	string src;
	string dest;
protected:
	double convert(double src);
	string getSourceString() { return src; }
	string getDestString() { return dest; }
public:
	WonToDollar(double ratio) : Converter(ratio) { src = "��"; dest = "�޷�"; }
};

double WonToDollar::convert(double src) {
	double tmp;
	tmp = src / ratio;
	return tmp;
}

class KmToMile : public Converter {
	string src;
	string dest;
protected:
	double convert(double src);
	string getSourceString() { return src; }
	string getDestString() { return dest; }
public:
	KmToMile(double ratio) : Converter(ratio) { src = "Km"; dest = "Mile"; }
};

double KmToMile::convert(double src) {
	double tmp;
	tmp = src / ratio;
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	WonToDollar wtd(1010);
	wtd.run();

	KmToMile ktm(1.609344);
	ktm.run();
}