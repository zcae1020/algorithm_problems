#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int r, c, ans;
string m[20];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void dfs(pii cur, int visited, int cnt)
{
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++)
    {
        pii next = {cur.x + dx[i], cur.y + dy[i]};
        if (next.x < 0 || next.y < 0 || next.x >= r || next.y >= c ||
            visited & 1 << m[next.x][next.y] - 'A')
            continue;

        dfs(next, visited | 1 << m[next.x][next.y] - 'A', cnt + 1);
    }
}

void Solution()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> m[i];

    dfs(pii(0, 0), 1 << m[0][0] - 'A', 1);

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}