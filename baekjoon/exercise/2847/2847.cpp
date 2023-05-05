#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[100], ans;

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[i + 1]) {
            ans += arr[i] - (arr[i + 1] - 1);
            arr[i] = arr[i + 1] - 1;
        }
    }
    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
