#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, a;
priority_queue<int> pq;

void Solution() {
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        cin >> a;
        pq.push(-a);
        if (pq.size() > n) {
            pq.pop();
        }
    }

    cout << -pq.top();
}

int main() {
    FASTIO
    Solution();
}