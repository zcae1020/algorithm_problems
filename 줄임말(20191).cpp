#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

char S[1000006], T[100005];
vector<int> Ta[26];
int slen, tlen;

int main() {
	cin >> S >> T;
	slen = strlen(S), tlen = strlen(T);

	for (int i = 0;i < tlen;i++)
		Ta[T[i] - 'a'].push_back(i);
	int sidx = 0, tidx = 0, res = 1, curAlpa;
	while (sidx != slen) {
		curAlpa = S[sidx] - 'a';
		if (Ta[curAlpa].empty()) {
			cout << -1;
			return 0;
		}
		int pos = lower_bound(Ta[curAlpa].begin(), Ta[curAlpa].end(), tidx) - Ta[curAlpa].begin();
		if (pos >= Ta[curAlpa].size()) {
			pos = 0;
			res++;
		}
		tidx = Ta[curAlpa][pos] + 1;
		sidx++;
	}
	cout << res;
}