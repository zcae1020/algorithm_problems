#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

void Solution()
{
    int x1, x2, y1, y2, n, ans = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    while (n--)
    {
        int x, y, r;
        cin >> x >> y >> r;

        if (!((x - x1) * (x - x1) + (y - y1) * (y - y1) < r * r) 
            == (x - x2) * (x - x2) + (y - y2) * (y - y2) < r * r)
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}