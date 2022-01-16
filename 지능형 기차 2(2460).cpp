#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int p = 0, mx = 0;
	for (int i = 0;i < 10;i++) {
		int up, down;
		cin >> down >> up;
		p -= down, p += up;
		mx = max(mx, p);
	}
	cout << mx;
}