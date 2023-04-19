#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[10000];

bool cmp(int a, int b) { return a > b; }

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            for (int j = n - 1; j > i; j--) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                    sort(arr + i + 1, arr + n, cmp);

                    for (int k = 0; k < n; k++) {
                        cout << arr[k] << ' ';
                    }
                    return;
                }
            }
        }
    }

    cout << -1;
}

int main() {
    FASTIO
    Solution();
}
