#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, box[101];

void Solution() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        box[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swap(box[a], box[b]);
    }

    for (int i = 1; i <= n; i++) {
        cout << box[i] << ' ';
    }
}

int main() {
    FASTIO
    Solution();
}
