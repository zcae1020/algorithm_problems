#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string a, b, ans;
bool carry;

void Solution() {
    cin >> a >> b;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
        int an = (i >= 0 ? a[i] - '0' : 0), bn = (j >= 0 ? b[j] - '0' : 0);
        int num = an + bn + carry;
        carry = num >= 10;
        num = num >= 10 ? num - 10 : num;
        ans.push_back(num + '0');
    }
    if (carry) {
        ans.push_back('1');
    }

    reverse(ans.begin(), ans.end());

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}