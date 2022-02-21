#include <iostream>
#include <algorithm>

using namespace std;

long long x, y, w, s;
long long ans;

int main() {
	cin >> x >> y >> w >> s;

	if (x < y)swap(x, y);
	if ((x + y) % 2) {
		ans = w;
		ans += min((x + y - 1)*w, min((x - 1)*s, y*s + (x - y - 1)*w));
	}
	else {
		ans = 0;
		ans += min((x + y)*w, min(x*s, y*s + (x - y)*w));
	}
	cout << ans;
}