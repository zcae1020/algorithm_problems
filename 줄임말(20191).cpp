#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

char S[1000006], T[100005];
int Salpa[26] = { 0 }, Talpa[26] = { 0 }, slen, tlen;
double divide[26];

int main() {
	cin >> S >> T;
	slen = strlen(S), tlen = strlen(T);

	for (int i = 0;i < slen;i++)
		Salpa[S[i] - 'a']++;
	for (int i = 0;i < tlen;i++)
		Talpa[T[i] - 'a']++;
	for (int i = 0;i < 26;i++) {
		if (Salpa[i] && !Talpa[i]) {
			cout << -1;
			return 0;
		}
	}
	int sidx = 0, res = 1;
	for (int i = 0;i <= tlen;i++) {
		if (sidx == slen)
			break;
		if (i == tlen) {
			res++;
			i = 0;
		}
		if (S[sidx] == T[i])
			sidx++;
	}
	cout << res;
}