#include <iostream>
#include <vector>
#define pii pair<int,int>

using namespace std;

int N, t, x, y, score, blue[4][6], green[6][4];
vector<pii> Bblock, Gblock;

void moveBlue() {
	int bp = 0;
	while (true) {
		for (auto a : Bblock) {
			if (blue[a.first][a.second + 1] || a.second + 1 >= 6) {
				bp = 1;
				break;
			}
		}

		if (bp) break;

		for (int i = 0; i < Bblock.size(); i++) Bblock[i].second++;
	}

	for (auto a : Bblock) blue[a.first][a.second] = 1;
}

void moveGreen() {
	int bp = 0;
	while (true) {
		for (auto a : Gblock) {
			if (green[a.first + 1][a.second] || a.first + 1 >= 6) {
				bp = 1;
				break;
			}
		}

		if (bp) break;

		for (int i = 0; i < Gblock.size(); i++) Gblock[i].first++;
	}

	for (auto a : Gblock) green[a.first][a.second] = 1;
}

void moveBlock() {
	Bblock.clear();
	Gblock.clear();
	if (t == 1) {
		Bblock.push_back({ x,0 });
		Gblock.push_back({ 0,y });
	}
	else if (t == 2) {
		Bblock.push_back({ x,0 });
		Bblock.push_back({ x,1 });
		Gblock.push_back({ 0,y });
		Gblock.push_back({ 0,y + 1 });
	}
	else {
		Bblock.push_back({ x,0 });
		Bblock.push_back({ x + 1,0 });
		Gblock.push_back({ 0,y });
		Gblock.push_back({ 1,y });
	}
	moveBlue();
	moveGreen();
}

void greenDown(int idx) {
	Gblock.clear();
	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j]) {
				green[i][j] = 0;
				Gblock.push_back({ i + 1,j });
			}
		}
	}

	for (auto a : Gblock) green[a.first][a.second] = 1;
}

void blueDown(int idx) {
	Bblock.clear();
	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[j][i]) {
				blue[j][i] = 0;
				Bblock.push_back({ j,i + 1 });
			}
		}
	}

	for (auto a : Bblock) blue[a.first][a.second] = 1;
}

void getScore() {
	for (int i = 2; i < 6; i++) {
		if (green[i][0] && green[i][1] && green[i][2] && green[i][3]) {
			green[i][0] = green[i][1] = green[i][2] = green[i][3] = 0;
			greenDown(i);
			score++;
		}
		if (blue[0][i] && blue[1][i] && blue[2][i] && blue[3][i]) {
			blue[0][i] = blue[1][i] = blue[2][i] = blue[3][i] = 0;
			blueDown(i);
			score++;
		}
	}
}

bool isOutOfGreen() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (green[j][i]) return true;
		}
	}
	return false;
}

bool isOutOfBlue() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (blue[i][j]) return true;
		}
	}
	return false;
}

void outOfMap() {
	while (isOutOfGreen()) {
		green[5][0] = green[5][1] = green[5][2] = green[5][3] = 0;
		greenDown(5);
	}
	while (isOutOfBlue()) {
		blue[0][5] = blue[1][5] = blue[2][5] = blue[3][5] = 0;
		blueDown(5);
	}
}

int getTile() {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 6; j++) {
			if (blue[i][j]) ret++;
			if (green[j][i]) ret++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> N;
	while (N--) {
		cin >> t >> x >> y;
		moveBlock();
		getScore();
		outOfMap();
	}
	cout << score << '\n' << getTile();
}