#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n;
ll arr[5000], ans = LONG_LONG_MAX;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        ll cur = 0, tans = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            tans += cur / arr[j] + 1;
            cur = arr[j] * (cur / arr[j] + 1);
        }
        cur = 0;
        for (int j = i + 1; j < n; j++)
        {
            tans += cur / arr[j] + 1;
            cur = arr[j] * (cur / arr[j] + 1);
        }
        ans = min(ans, tans);
    }
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}