#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int a, b, c, d;

pii makeGiyak(int son, int par) {
    for (int i = 2; i <= par; i++) {
        if (par % i == 0 && son % i == 0) {
            par /= i;
            son /= i;
            i--;
        }
    }

    return {son, par};
}

void Solution() {
    cin >> a >> b >> c >> d;

    pii b1 = makeGiyak(a, b), b2 = makeGiyak(c, d);

    int par = b1.sd * b2.sd, son = b2.fs * b1.sd + b1.fs * b2.sd;

    pii ans = makeGiyak(son, par);

    cout << ans.fs << ' ' << ans.sd;
}

int main() {
    FASTIO
    Solution();
}