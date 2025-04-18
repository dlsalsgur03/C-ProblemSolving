#include <iostream>

using namespace std;

class Color {
	int red, green, blue;
public:
	Color(int red = 0, int green = 0, int blue = 0);
	void show();
	Color operator+ (Color op);
	bool operator== (Color op);
};

Color::Color(int red, int green, int blue) {
	this->red = red; this->green = green; this->blue = blue;
}
void Color::show() { cout << red << ' ' << green << ' ' << blue << '\n'; }
Color Color::operator+ (Color op) {
	Color tmp;
	tmp.red = red + op.red;
	tmp.green = green + op.green;
	tmp.blue = blue + op.blue;
	return tmp;
}
bool Color::operator== (Color op) {
	if (red == op.red && green == op.green && blue == op.blue) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}
