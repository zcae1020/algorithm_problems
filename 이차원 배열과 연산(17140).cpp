#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[100][100], cr, cc, nr, nc, r, c, k;
vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

void draw(int x, int y, int d) {
	int idx = 0;
	if (d == 0) {
		for (auto p : v) {
			if (idx >= 100) break;
			A[y][idx++] = p.first;
			A[y][idx++] = p.second;
		}
		for (int i = idx; i < 100; i++)
			A[y][i] = 0;
	}
	else {
		for (auto p : v) {
			if (idx >= 100) break;
			A[idx++][x] = p.first;
			A[idx++][x] = p.second;
		}
		for (int i = idx; i < 100; i++)
			A[i][x] = 0;
	}
}

void getVector(int x, int y, int d) {
	int tmp[101] = { 0 };
	if (d == 0) for (int i = 0; i < cr; i++) tmp[A[y][i]]++;
	else for (int i = 0; i < cc; i++) tmp[A[i][x]]++;

	for (int i = 1; i <= 100; i++) {
		if (tmp[i]) v.push_back(make_pair(i, tmp[i]));
	}
}

void opR() {
	nc = 0;
	for (int i = 0; i < cr; i++) {
		getVector(0, i, 0);
		nc = max(nc, (int)v.size() * 2);
		sort(v.begin(), v.end(), comp);
		draw(0, i, 0);
		v.clear();
	}
	cc = nc > 100 ? 100 : nc;
}

void opC() {
	nr = 0;
	for (int i = 0; i < cc; i++) {
		getVector(i, 0, 1);
		nr = max(nr, (int)v.size() * 2);
		sort(v.begin(), v.end(), comp);
		draw(i, 0, 1);
		v.clear();
	}
	cr = nr > 100 ? 100 : nr;
}

void Input() {
	cr = cc = 3;
	cin >> r >> c >> k;
	r--, c--;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
}

void Solution() {
	int t = 0;
	while (t <= 100) {
		if (A[r][c] == k) {
			cout << t;
			return;
		}

		if (cr >= cc) opR();
		else opC();
		t++;
	}
	cout << -1;
}

int main() {
	Input();
	Solution();
}