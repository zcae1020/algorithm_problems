#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char str[20];

int cal(int idx, int num1, int num2) {
	switch (str[idx]) {
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	}
}

int dfs(int idx, int cur) {
	if (idx == N - 1)
		return cur;
	if (idx + 4 < N) {
		int form = cal(idx + 1, cur, str[idx + 2] - '0');
		int latt = cal(idx + 1, cur, cal(idx + 3, str[idx + 2] - '0', str[idx + 4] - '0'));
		int fdfs = dfs(idx + 2, form), ldfs = dfs(idx + 4, latt);
		int mx = fdfs > ldfs ? fdfs : ldfs;
		return mx;
	}
	else if (idx + 2 < N) {
		int d = cal(idx + 1, cur, str[idx + 2] - '0');
		return dfs(idx + 2, d);
	}
}

int main() {
	cin >> N >> str;

	cout << dfs(0, str[0] - '0');
}