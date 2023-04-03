#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int ans;
char cur;
string input;

void Solution() {
    cin >> input;

    for (auto a : input) {
        ans += cur != a ? 10 : 5;
        cur = a;
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}