#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int r, c, m[1000][1000], dp[1000][1000];

int dx[3] = {0, 1, 1}, dy[3] = {1, 0, 1};

void Solution()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
            dp[i][j] = m[i][j];
        }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < r && ny < c)
                    dp[nx][ny] = max(dp[nx][ny], dp[i][j] + m[nx][ny]);
            }
        }
    }
    cout << dp[r - 1][c - 1];
}

int main()
{
    FASTIO
    Solution();
}