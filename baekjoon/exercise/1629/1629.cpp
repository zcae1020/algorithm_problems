#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll A, B, C;

ll f(ll n)
{
    if (n == 1)
        return A % C;
    if (n % 2)
        return (A * f(n - 1)) % C;
    ll v = f(n / 2) % C;
    return (v * v) % C;
}

void Solution()
{
    cin >> A >> B >> C;
    cout << f(B);
}

int main()
{
    FASTIO
    Solution();
}