#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N;
vector<int> ans;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void getAns(int cur, int cnt) {
    if (cnt == 0) {
        ans.push_back(cur);
        return;
    }

    for (int i = 1; i < 10; i++) {
        if (cnt == N && i == 1)
            continue;
        int next = cur * 10 + i;
        if (isPrime(next)) {
            getAns(next, cnt - 1);
        }
    }
}

void Solution() {
    cin >> N;
    getAns(0, N);
    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}
