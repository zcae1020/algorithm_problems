#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[1000000];

bool cmp(int a, int b) { return a > b; }

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}