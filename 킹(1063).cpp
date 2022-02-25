#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;

int kx, ky, rx, ry;
int dx[8] = { 0,0,1,1,1,-1,-1,-1 }, dy[8] = { 1,-1,1,-1,0,1,-1,0 };

int main() {
	m.insert(make_pair("R", 0));
	m.insert(make_pair("L", 1));
	m.insert(make_pair("B", 7));
	m.insert(make_pair("T", 4));
	m.insert(make_pair("RT", 2));
	m.insert(make_pair("LT", 3));
	m.insert(make_pair("RB", 5));
	m.insert(make_pair("LB", 6));

	string k, r, d;
	int n, nx, ny, rnx, rny, dirc;
	cin >> k >> r >> n;
	kx = k[1] - '1', ky = k[0] - 'A';
	rx = r[1] - '1', ry = r[0] - 'A';
	while (n--) {
		cin >> d;
		dirc = m[d];
		nx = kx + dx[dirc], ny = ky + dy[dirc];
		if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8)
			continue;
		if (nx == rx && ny == ry) {
			rnx = rx + dx[dirc], rny = ry + dy[dirc];
			if (rnx < 0 || rny < 0 || rnx >= 8 || rny >= 8)
				continue;
			rx = rnx, ry = rny;
		}
		kx = nx, ky = ny;
	}
	char ka[3] = "A1", ra[3] = "A1";
	ka[0] += ky, ka[1] += kx;
	ra[0] += ry, ra[1] += rx;
	cout << ka << endl << ra;
}