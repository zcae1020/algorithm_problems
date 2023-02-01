#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, ans;
vector<vector<pii>> v;

void over(int l, int r, int idx) {
    int s = v[idx].size();
    for (int i = 0; i < s; i++) {
        pii p = v[idx][i];

        if (p.fs >= p.sd || p.fs >= r || p.sd <= l) {
            continue;
        }

        if (p.fs <= l) {
            if (p.sd <= r) {
                v[idx][i].sd = l;
            } else {
                v[idx].push_back({r, v[idx][i].sd});
                v[idx][i].sd = l;
            }
        } else {
            if (p.sd <= r) {
                v[idx][i].sd = v[idx][i].fs;
            } else {
                v[idx][i].fs = r;
            }
        }
    }
}

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<pii> tmp;
        int l, r;
        cin >> l >> r;
        r++;
        for (int i = 0; i < v.size(); i++) {
            over(l, r, i);
        }

        tmp.push_back({l, r});
        v.push_back(tmp);
    }

    for (auto a : v) {
        bool flag = false;
        for (auto b : a) {
            flag = flag | b.fs < b.sd;
        }
        ans += flag;
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}