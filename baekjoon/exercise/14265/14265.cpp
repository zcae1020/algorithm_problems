#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll K, A, B;

ll get(ll k, ll x, ll even)
{
    if (x < 0 || k > x)
        return 0;
    if (k == 0)
        return x + 1;

    for (ll i = 0, ret = 0;; ret += (1LL << (i++ + even)))
    {
        if (k * (1LL << i) <= x && x < k * (1LL << (i + 1)))
        {
            ll r = x - k * (1LL << i) + 1LL;
            if (r <= (1LL << (i + even)))
                return ret + r;
            else
                return ret + (1LL << (i + even));
        }
    }
    return 0LL;
}

void Solution()
{
    cin >> K >> A >> B;

    cout << get(K, B, !(K & 1)) - get(K, A - 1, !(K & 1));
}

int main()
{
    FASTIO
    Solution();
}