#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

char S[1000006], T[100005];
int Salpa[26] = { 0 }, Talpa[26] = { 0 }, slen, tlen;
double divide[26];

int compare() { //return: idx
	int sidx = 0;
	for (int i = 0;i < tlen;i++) {
		if (S[sidx] == T[i])
			sidx++;
	}
	return sidx;
}

int main() {
	cin >> S >> T;
	slen = strlen(S), tlen = strlen(T);
	int c = compare();
	if (c == slen) {
		cout << 1;
		return 0;
	}
	for (int i = c;i < slen;i++) {
		Salpa[S[i] - 'a']++;
	}
	for (int i = 0;i < tlen;i++) {
		Talpa[T[i] - 'a']++;
	}
	for (int i = 0;i < 26;i++) {
		if (Salpa[i] && Talpa[i])
			divide[i] = (double)Salpa[i] / (double)Talpa[i];
		else if (Salpa[i] && !Talpa[i]) {
			cout << -1;
			return 0;
		}
		else
			divide[i] = -1;
	}
	double mx = -1;
	for (int i = 0;i < 26;i++) {
		mx = max(mx, divide[i]);
	}
	cout << ceil(mx) + 1;
}