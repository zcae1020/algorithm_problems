#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, k, ans;

void Solution()
{
    cin >> n >> m >> k;
    ans = min(n / 2, m);
    k -= n - 2 * ans + m - ans;

    while (k > 0)
    {
        k -= 3;
        ans--;
    }

    cout << (ans > 0 ? ans : 0);
}

int main()
{
    FASTIO
    Solution();
}