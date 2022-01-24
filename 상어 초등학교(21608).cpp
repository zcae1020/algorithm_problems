#include <iostream>
#include <vector>
#include <cstring>
#define pii pair<int,int>

using namespace std;

int N, prefer[20][5], map[20][20];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

pii sCondition(vector<pii> v) {
	int mx = 0;
	vector<pii> ret;
	for (int i = 0;i < v.size();i++) {
		pii cur = v[i];
		int emp = 0;
		for (int j = 0;j < 4;j++) {
			pii next = { cur.first + dx[j],cur.second + dy[j] };
			if (!(next.first >= 0 && next.first < N&&next.second >= 0 && next.second < N))
				continue;
			if (!map[next.second][next.first])
				emp++;
		}
		if (mx == emp)
			ret.emplace_back(cur);
		else if (mx < emp) {
			ret.clear();
			ret.emplace_back(cur);
			mx = emp;
		}
	}
	return ret[0];
}

pii fCondition(int idx) {
	int mx = 0;
	vector<pii> v;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			pii cur = { j,i };
			if (map[cur.second][cur.first])
				continue;
			int cp = 0;
			for (int k = 0;k < 4;k++) {
				pii next = { cur.first + dx[k],cur.second + dy[k] };
				if (!(next.first >= 0 && next.first < N&&next.second >= 0 && next.second < N) || !map[next.second][next.first])
					continue;
				for (int l = 1;l <= 4;l++) {
					if (prefer[idx][l] == map[next.second][next.first]) {
						cp++;
						break;
					}
				}
			}
			if (mx == cp)
				v.emplace_back(cur);
			else if (mx < cp) {
				v.clear();
				v.emplace_back(cur);
				mx = cp;
			}
		}
	}
	if (v.size() == 1)
		return v[0];
	return sCondition(v);
}

void mapClear() {
	for (int i = 0;i < N;i++)
		memset(map[i], 0, sizeof(map[i]));
}

int findSatis() {
	int ret = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			pii cur = { j,i };
			int sat = 0, cidx;
			for (int k = 0;k < N*N;k++) {
				if (prefer[k][0] == map[cur.second][cur.first]) {
					cidx = k;
					break;
				}
			}
			for (int k = 0;k < 4;k++) {
				pii next = { cur.first + dx[k],cur.second + dy[k] };
				if (!(next.first >= 0 && next.first < N&&next.second >= 0 && next.second < N))
					continue;
				for (int l = 1;l <= 4;l++) {
					if (map[next.second][next.first] == prefer[cidx][l])
						sat++;
				}
			}
			if (sat) {
				int ten = 1;
				for (int i = 1;i < sat;i++)
					ten *= 10;
				ret += ten;
			}
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0;i < N * N;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> prefer[i][j];
		}
	}

	mapClear();
	map[1][1] = prefer[0][0];
	for (int i = 1;i < N * N;i++) {
		pii fc = fCondition(i);
		map[fc.second][fc.first] = prefer[i][0];
	}

	int satis = findSatis();
	cout << satis;
}