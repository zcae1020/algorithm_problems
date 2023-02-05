#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string s1, s2, ans, str;
map<char, vector<int>> m;

void getAns(int idx1, int idx2) {
    if (idx1 > s1.size() || idx2 > s2.size()) {
        if (ans.size() < str.size()) {
            ans = str;
        }
        return;
    }

    getAns(idx1, idx2 + 1);

    if (m[s2[idx2]].empty()) {
        return;
    }

    int idx = lower_bound(m[s2[idx2]].begin(), m[s2[idx2]].end(), idx1) -
              m[s2[idx2]].begin();

    if (idx != m[s2[idx2]].size()) {
        idx1 = m[s2[idx2]][idx];
        str.push_back(s1[idx1]);
        getAns(idx1 + 1, idx2 + 1);
        str.pop_back();
    }
}

void Solution() {
    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++) {
        m[s1[i]].push_back(i);
    }

    for (int i = 0; i < s2.size(); i++) {
        getAns(0, i);
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}