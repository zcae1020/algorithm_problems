#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct tae {
	int from;
	int to;
	int box;
}Ta;

bool comp(Ta t1, Ta t2) {
	if (t1.to == t2.to)
		return t1.from < t2.from;
	return t1.to < t2.to;
}

int N, C, M;
int map[2001];
vector<Ta> v;

int getMax(Ta t) {
	int ret = 0;
	for (int i = t.from;i < t.to;i++)
		ret = max(ret, map[i]);
	return ret;
}

void putValue(Ta t, int value) {
	for (int i = t.from;i < t.to;i++)
		map[i] += value;
}

int main() {
	cin >> N >> C >> M;
	for (int i = 0;i < M;i++) {
		Ta t;
		cin >> t.from >> t.to >> t.box;
		v.push_back(t);
	}

	sort(v.begin(), v.end(), comp);

	int ans = 0, mx, value;
	for (int i = 0;i < M;i++) {
		mx = getMax(v[i]);
		if (C - mx > v[i].box)
			value = v[i].box;
		else
			value = C - mx;
		ans += value;
		putValue(v[i], value);
	}

	cout << ans;
}