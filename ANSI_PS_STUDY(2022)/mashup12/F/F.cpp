#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 2e5 + 10;

int n;
ll psum[maxn];
map<ll, int> m;

void Solution()
{
    cin >> n;
    for (int i = 2; i <= n + 1; i++)
    {
        int a;
        cin >> a;
        psum[i] = psum[i - 1] + a;
    }

    m[0] = 1;
    int cnt_max = 0;
    ll ans = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        ll num = psum[i];
        cnt_max = max(cnt_max, m[num]);
        ans += i - cnt_max - 1;
        m[num] = i;
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}