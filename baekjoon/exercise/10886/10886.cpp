#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, a, isCute[2];

void Solution() {
    cin >> n;
    while (n--) {
        cin >> a;
        isCute[a]++;
    }

    cout << (isCute[0] > isCute[1] ? "Junhee is not cute!" : "Junhee is cute!");
}

int main() {
    FASTIO
    Solution();
}
