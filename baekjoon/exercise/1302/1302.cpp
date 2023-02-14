#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

struct compare {
    bool operator()(pair<int, string> a, pair<int, string> b) {
        if (a.fs == b.fs) {
            return a.sd > b.sd;
        }

        return a.fs < b.fs;
    }
};

int n;
map<string, int> m;
priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        m[x]++;
    }

    for (auto a : m) {
        pq.push({a.sd, a.fs});
    }

    cout << pq.top().sd;
}

int main() {
    FASTIO
    Solution();
}