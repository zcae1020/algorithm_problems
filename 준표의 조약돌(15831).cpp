#include <iostream>
#include <algorithm>

using namespace std;

int N, B, W, b, w, s, ans;
char a[300000];

int main() {
	cin >> N >> B >> W;

	for (int i = 0; i < N; i++) {
		cin >> a[i];

		if (a[i] == 'W')
			w++;
		if (a[i] == 'B') {
			b++;
			while (b > B) {
				if (a[s] == 'W') w--;
				if (a[s] == 'B') b--;
				s++;
			}
		}

		if (w >= W && b <= B) ans = max(ans, i - s + 1);
	}

	cout << ans;
}