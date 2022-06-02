#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m[100][100], ans[100][100];

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        q.push(i);

        while (q.size())
        {
            int cur = q.front();
            q.pop();

            for (int j = 0; j < n; j++)
            {
                if ((ans[cur][j] || m[cur][j]) && ans[i][j] == 0)
                {
                    ans[i][j] = 1;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}