#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, k;

int getAns(int all, int restm, int left, int right) {
    if ((restm == 0 && left == 0) || all == 1) {
        return 0;
    }

    int ret = 1;
    if (restm && right) {
        if (right > left) {
            ret += getAns(all / 2, restm - 1, left, right - 1 - left);
        } else {
            right--;
            left -= right;
            ret += getAns(all / 2, restm - 1, right + left / 2, 0);
        }
    } else {
        ret += getAns(all / 2, restm, (left - 1) / 2, right / 2);
    }
    return ret;
}

void Solution() {
    cin >> n >> m >> k;
    cout << getAns(n, m, k - 1, n - k);
}

int main() {
    FASTIO
    Solution();
}
