#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const string order = "ACGT";
int n, m, cnt, ans[50];
string arr[1000];

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int mx = 0;
        vector<int> v(4);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                v[k] += order[k] == arr[j][i];
            }
        }

        for (int k = 0; k < 4; k++) {
            if (mx < v[k]) {
                mx = v[k];
                ans[i] = k;
            }
        }

        cnt += n - v[ans[i]];
    }

    for (int i = 0; i < m; i++) {
        cout << order[ans[i]];
    }
    cout << '\n' << cnt;
}

int main() {
    FASTIO
    Solution();
}