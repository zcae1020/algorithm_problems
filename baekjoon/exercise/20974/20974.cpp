#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, odd, even;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2)
        {
            odd++;
        }
        else
            even++;
    }

    if (odd == even || odd + 1 == even)
    {
        cout << odd + even;
    }
    else if (odd > even)
    {
        int ans = even * 2;
        if ((odd - even) % 3 == 1)
        {
            ans--;
        }
        if ((odd - even) % 3 == 2)
        {
            ans++;
        }
        cout << ans + (odd - even) / 3 * 2;
    }
    else
    {
        cout << 2 * odd + 1;
    }
}

int main()
{
    FASTIO
    Solution();
}