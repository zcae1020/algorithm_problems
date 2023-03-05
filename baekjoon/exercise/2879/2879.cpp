#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[1000], ans, start;

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] -= x;
    }

    if (n == 1) {
        cout << abs(arr[0]);
        return;
    }

    start = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] >= 0) {
            if (start < 0) {
                ans += abs(start);
                start = arr[i];
            } else if (arr[i] > start) { // 오름차순 o
                start = arr[i];
            } else { // 오름차순 x
                ans += abs(start) - abs(arr[i]);
                start = arr[i];
            }
        } else {
            if (start > 0) {
                ans += abs(start);
                start = arr[i];
            } else if (arr[i] < start) { // 내림차순 o
                start = arr[i];
            } else { // 내림차순 x
                ans += abs(start) - abs(arr[i]);
                start = arr[i];
            }
        }
    }

    ans += abs(start);
    cout << ans;
}

int main() {
    FASTIO
    Solution();
}