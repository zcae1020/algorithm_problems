#include <iostream>

using namespace std;

int x, y, d;

int N, sand[499][499], ans = 0;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 }; //0:l, 1:d, 2:r, 3:u
int sx[10] = { 0,-1,1,-2,-1,1,2,-1,1,0 }, sy[10] = { -2,-1,-1,0,0,0,0,1,1,-1 }, sc[10] = { 5,10,10,2,7,7,2,1,1,0 };
/*
* d에 따라 s값이 바뀜
* d: -sx<->-sy
* r: -sx, -sy
* u: sx<->sy
*/ 

void Input() {
	cin >> N;
	x = y = N / 2;
	d = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sand[i][j];
		}
	}
}

void Solution() {
	int move = 0, maxMove = 1, flag = 1;
	while (true) {
		if (x == 0 && y == 0) break;

		if (move == maxMove) {
			move = 0;
			if (flag == 2) {
				flag = 0;
				maxMove++;
			}
			d = (d + 1) % 4;
			flag++;
		}

		int tnx = x + dx[d], tny = y + dy[d], tns = sand[tnx][tny];
		move++;

		int snx, sny, sna;
		for (int i = 0; i < 10; i++) {
			if (d == 0) {
				snx = tnx + sx[i], sny = tny + sy[i], sna = i == 9 ? sand[tnx][tny] : tns * sc[i] / 100;
				sand[tnx][tny] -= sna;
				if (snx < 0 || sny < 0 || snx >= N || sny >= N)ans += sna;
				else sand[snx][sny] += sna;
			}
			else if (d == 1) {
				snx = tnx - sy[i], sny = tny - sx[i], sna = i == 9 ? sand[tnx][tny] : tns * sc[i] / 100;
				sand[tnx][tny] -= sna;
				if (snx < 0 || sny < 0 || snx >= N || sny >= N)ans += sna;
				else sand[snx][sny] += sna;
			}
			else if (d == 2) {
				snx = tnx - sx[i], sny = tny - sy[i], sna = i == 9 ? sand[tnx][tny] : tns * sc[i] / 100;
				sand[tnx][tny] -= sna;
				if (snx < 0 || sny < 0 || snx >= N || sny >= N)ans += sna;
				else sand[snx][sny] += sna;
			}
			else {
				snx = tnx + sy[i], sny = tny + sx[i], sna = i == 9 ? sand[tnx][tny] : tns * sc[i] / 100;
				sand[tnx][tny] -= sna;
				if (snx < 0 || sny < 0 || snx >= N || sny >= N)ans += sna;
				else sand[snx][sny] += sna;
			}
		}

		x = tnx, y = tny;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	Input();
	Solution();
}