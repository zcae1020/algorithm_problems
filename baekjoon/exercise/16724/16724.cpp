#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m, visited[1005][1005], vidx, ans;
string MAP[1005];
bool addAns;

void Solution()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> MAP[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                vidx++;
                addAns = false;
                queue<pii> q;
                q.push({i, j});

                while (q.size())
                {
                    pii c = q.front();
                    q.pop();

                    if (visited[c.first][c.second])
                    {
                        if (!addAns && visited[c.first][c.second] == vidx)
                        {
                            ans++;
                            fjsda
                            //addAns = true;
                        }
                        continue;
                    }

                    visited[c.first][c.second] = vidx;

                    if (MAP[c.first][c.second] == 'D')
                        c.first++;
                    else if (MAP[c.first][c.second] == 'U')
                        c.first--;
                    else if (MAP[c.first][c.second] == 'L')
                        c.second--;
                    else if (MAP[c.first][c.second] == 'R')
                        c.second++;

                    q.push(c);
                }
            }
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}