#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;
queue<int> q;

void Solution() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }
}

int main() {
    FASTIO
    Solution();
}