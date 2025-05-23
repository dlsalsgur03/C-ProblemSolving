#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << " " << green << " " << blue << "\n"; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor;
	p->show();
	Color colors[3];
	p = colors;

	p->setColor(255, 0, 0);
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

	p->show();
	(p + 1)->show();
	(p + 2)->show();
}
