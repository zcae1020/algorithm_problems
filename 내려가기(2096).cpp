#include <iostream>
#include <algorithm>

using namespace std;

int n, d[3][2];
int dx[3] = { -1,0,1 };

int main() {
	int x, tmp[3][2];
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> x;

			if (i == 0) {
				d[j][0] = d[j][1] = x;
				continue;
			}

			int mx = 0, mn = 1000006;
			for (int k = 0;k < 3;k++) {
				int nx = j + dx[k];
				if (nx < 0 || nx >= 3)
					continue;
				mx = max(mx, d[nx][0]);
				mn = min(mn, d[nx][1]);
			}
			tmp[j][0] = x + mx;
			tmp[j][1] = x + mn;
		}
		if (i) {
			for (int j = 0;j < 3;j++) {
				d[j][0] = tmp[j][0];
				d[j][1] = tmp[j][1];
			}
		}
	}

	int mx = 0, mn = 1000006;
	for (int i = 0;i < 3;i++) {
		mx = max(mx, d[i][0]);
		mn = min(mn, d[i][1]);
	}
	cout << mx << ' ' << mn;
}