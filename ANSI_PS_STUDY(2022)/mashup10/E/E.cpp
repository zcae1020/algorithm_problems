#include <iostream>

using namespace std;

char s[1001][1001];
int map[1000][1000];
int n, m, q, cnt;

void Input()
{
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];

            if (s[i][j] == '*')
                cnt++;

            if (j == 0)
                map[i][j] = s[i][j] == '*' ? 1 : 0;
            else
                map[i][j] = s[i][j] == '*' ? map[i][j - 1] + 1 : map[i][j - 1];
        }
    }
}

void Solution()
{
    int x, y, cur, ans;
    while (q--)
    {
        ans = 0;

        cin >> x >> y;
        x--, y--;

        if (s[x][y] == '*')
        {
            s[x][y] = '.';
            cnt--;
            for (int i = y; i < m; i++)
                map[x][i]--;
        }
        else
        {
            s[x][y] = '*';
            cnt++;
            for (int i = y; i < m; i++)
                map[x][i]++;
        }

        int a = (cnt - 1) % n, b = (cnt - 1) / n;
        if (cnt == 0)
            a = b = 0;

        if (b > 0 && a < n - 1)
            for (int i = a + 1; i < n; i++)
                ans += map[i][b - 1];

        for (int i = 0; i <= a; i++)
            ans += map[i][b];

        ans = cnt - ans;

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}