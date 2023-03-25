#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int ans;
string s1, s2;

void Solution() {
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i + s2.size() <= s1.size(); i++) {
        if (s1.substr(i, s2.size()) == s2) {
            ans++;
            i += s2.size();
            i--;
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}