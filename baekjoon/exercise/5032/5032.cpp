#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int e, f, c, ans;

void Solution()
{
    cin >> e >> f >> c;

    e += f;
    while (e >= c)
    {
        int n = e / c;
        ans += n;
        e %= c;
        e += n;
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}