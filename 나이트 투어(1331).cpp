#include <iostream>

using namespace std;

int dx[8] = { -2,-2,-1,-1,1,1,2,2 }, dy[8] = { -1,1,-2,2,-2,2,-1,1 };
int sx, sy, cx, cy, nx, ny, t = 36;
bool v[6][6], check;
char p[3];

int main() {
	cin >> p;
	cx = p[0] - 'A', cy = p[1] - '1';
	sx = cx, sy = cy;
	v[cy][cx] = 1;
	while (--t) {
		check = 0;
		cin >> p;
		nx = p[0] - 'A', ny = p[1] - '1';
		for (int i = 0;i < 8;i++) {
			if (cx + dx[i] == nx && cy + dy[i] == ny) {
				check = 1;
				break;
			}
		}
		if (!check || v[ny][nx]) {
			cout << "Invalid";
			exit(0);
		}
		cx = nx, cy = ny;
		v[cy][cx] = 1;
	}
	check = 0;
	for (int i = 0;i < 8;i++) {
		if (cx + dx[i] == sx && cy + dy[i] == sy) {
			check = 1;
			break;
		}
	}
	if (check)
		cout << "Valid";
	else
		cout << "Invalid";
}