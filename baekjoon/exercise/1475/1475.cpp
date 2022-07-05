#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int arr[10], ans = 0;

void Solution()
{
    string s;
    cin >> s;
    for (auto a : s)
        arr[a - '0']++;

    for (int i = 0; i < 9; i++)
    {
        if (i == 6)
            continue;
        ans = max(ans, arr[i]);
    }

    ans = max(ans, (arr[6] + arr[9] + 1) / 2);
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}