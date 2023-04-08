#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const string order[] = {"black", "brown", "red",    "orange", "yellow",
                        "green", "blue",  "violet", "grey",   "white"};

int getIndex(string s) {
    for (int i = 0; i < 10; i++) {
        if (s == order[i]) {
            return i;
        }
    }
    return -1;
}

void Solution() {
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    int idx[] = {getIndex(a), getIndex(b), getIndex(c)};

    for (int i = 0; i < 3; i++) {
        if (ans == 0 && idx[i] == 0) {
            continue;
        }
        if (i == 2) {
            if(ans == 0) {
                continue;
            }
            cout << ans;
            for (int i = 0; i < getIndex(c); i++)
                cout << 0;
            return;
        }
        ans *= 10;
        ans += idx[i];
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
