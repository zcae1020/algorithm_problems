#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<string>> v;

int main() {
	cin >> k >> n;
	v.resize(k + 1);
	v[1].emplace_back("1");
	v[2].emplace_back("1+1");
	v[2].emplace_back("2");
	v[3].emplace_back("1+1+1");
	v[3].emplace_back("1+2");
	v[3].emplace_back("2+1");
	v[3].emplace_back("3");

	if (k <= 3) {
		if (v[k].size() < n) {
			cout << -1;
		}
		else {
			cout << v[k][n - 1];
		}
	}
	else {
		for (int i = 4;i <= k;i++) {
			for (int j = 1;j <= 3;j++) {
				for (string s : v[i - j]) {
					char num = j + '0';
					v[i].emplace_back(s + "+" + num);
				}
			}
		}
		sort(v[k].begin(), v[k].end());
		if (v[k].size() < n) {
			cout << -1;
		}
		else {
			cout << v[k][n - 1];
		}
	}
}