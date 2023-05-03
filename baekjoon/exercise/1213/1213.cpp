#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string s;
int cnt[26], flag, one;

void Solution() {
    cin >> s;
    for (auto c : s) {
        cnt[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2)
            one = i;
        flag += cnt[i] % 2;
    }

    if (flag > 1) {
        cout << "I'm Sorry Hansoo";
        return;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }

    if (flag) {
        cout << (char)('A' + one);
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }
}

int main() {
    FASTIO
    Solution();
}