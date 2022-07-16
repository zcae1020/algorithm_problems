#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, arr[8], ans;
bool visited[8];

void dfs(int cnt, int sum, int pre)
{
    if (cnt == n)
    {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        dfs(cnt + 1, cnt == 0 ? 0 : (sum + abs(pre - arr[i])), arr[i]);
        visited[i] = 0;
    }
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dfs(0, 0, 0);

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}