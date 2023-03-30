#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int len = 8;

string MAP[len];
int ans;

void Solution() {
    for (int i = 0; i < len; i++) {
        cin >> MAP[i];

        int x = (i % 2);
        for (int j = 0; j < 4; j++) {
            ans += MAP[i][x + j * 2] == 'F';
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
