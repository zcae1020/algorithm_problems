#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n[3], arr[3][1000], mn = 1e9, sum, discount;

bool cmp(int a, int b) { return a > b; }

void Solution() {
    for (int i = 0; i < 3; i++) {
        cin >> n[i];
        mn = min(mn, n[i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        sort(arr[i], arr[i] + n[i], cmp);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < mn; j++) {
            discount += arr[i][j];
        }
    }

    cout << sum << '\n' << sum - discount / 10;
}

int main() {
    FASTIO
    Solution();
}
