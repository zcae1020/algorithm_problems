#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> v(9);

int getNumber(int N, int cnt) {
	int ret = 0;
	while (cnt--) {
		ret *= 10;
		ret += N;
	}
	return ret;
}

int solution (int N, int number) {
	for (int i = 1;i <= 8;i++) {
		v[i].emplace_back(getNumber(N, i));
		for (int j = 1;j < i;j++) {
			for (int k : v[j]) {
				for (int l : v[i - j]) {
					v[i].emplace_back(k + l);
					v[i].emplace_back(k - l);
					v[i].emplace_back(k * l);
					if (l)
						v[i].emplace_back(k / l);
				}
			}
		}
		for (int j : v[i])
			if (j == number)
				return i;
	}
	return -1;
}