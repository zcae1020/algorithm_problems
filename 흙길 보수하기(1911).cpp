#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

vector<pii> water;
int N, L;

bool compare(pii a, pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	cin >> N >> L;
	int a, b;
	for (int i = 0;i < N;i++) {
		cin >> a >> b;
		water.emplace_back(a, b);
	}
	sort(water.begin(), water.end(), compare);

	int s, e, ans = 0, roadMx = 0;
	for (int i = 0;i < N;i++) {
		s = max(roadMx, water[i].first), e = water[i].second;
		if (e <= s)
			continue;
		int sub = e - s;
		if (!(sub % L)) {
			ans += sub / L;
			roadMx = e;
		}
		else {
			ans += sub / L + 1;
			roadMx = e + L - sub % L;
		}
	}
	cout << ans;
}