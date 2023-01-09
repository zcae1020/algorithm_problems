#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second
 
using namespace std;
 
const int mxn = 3e5;
 
int t, n, q, k[mxn], dp[mxn];
ll parr[mxn];
 
void Solution()
{
    cin >> t;
    while (t--)
    {
        memset(parr, 0, sizeof(parr));
        memset(dp, 0, sizeof(dp));
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            parr[i] = a + parr[i - 1];
            dp[i] = max(dp[i - 1], a);
        }
 
        for (int i = 0; i < q; i++)
        {
            cin >> k[i];
        }
 
        sort(k, k + q);
 
        int idx = 1;
        for (int i = 0; i < q; i++)
        {
            int idx = upper_bound(dp, dp + n + 1, k[i]) - dp;
            cout << parr[idx - 1] << ' ';
        }
        cout << '\n';
    }
}
 
int main()
{
    FASTIO
    Solution();
}