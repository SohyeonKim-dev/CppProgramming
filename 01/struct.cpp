#include <iostream>

struct Point {
	int xpos = 0;
	int ypos = 0;

	void MovePos(int x, int y) {
		xpos += x;
		ypos += y;
	}

	void AddPoint(const Point& pos) {
		xpos = xpos + pos.xpos;
		ypos = ypos + pos.ypos;
	}

	void ShowPosition() {
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

int main() {
	Point pos1 = { 12,4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}
