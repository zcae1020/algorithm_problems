#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 5e6;

int n, k, arr[maxn];

void Solution() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << arr[k - 1];
}

int main() {
    FASTIO
    Solution();
}
