#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int T, ans[3], t[3] = {300, 60, 10};

void Solution()
{
    cin >> T;
    for (int i = 0; i < 3; i++)
    {
        if (T >= t[i])
        {
            ans[i] = T / t[i];
            T %= t[i];
        }
    }

    if (T)
        cout << -1;
    else
        for (int i = 0; i < 3; i++)
            cout << ans[i] << ' ';
}

int main()
{
    FASTIO
    Solution();
}