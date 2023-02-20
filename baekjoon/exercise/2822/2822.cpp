#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int ans;
vector<int> v;
priority_queue<pii> pq;

void Solution() {
    for (int i = 1; i <= 8; i++) {
        int x;
        cin >> x;
        pq.push({x, i});
    }

    for (int i = 0; i < 5; i++) {
        ans += pq.top().fs;
        v.push_back(pq.top().sd);

        pq.pop();
    }

    sort(v.begin(), v.end());

    cout << ans << '\n';
    for (auto a : v) {
        cout << a << ' ';
    }
}

int main() {
    FASTIO
    Solution();
}