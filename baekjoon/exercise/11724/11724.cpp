#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

vector<int> v[1001];
int n, m, ans;
bool visited[1001];

void Solution()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (q.size())
            {
                int cur = q.front();
                q.pop();

                for (auto next : v[cur])
                {
                    if (!visited[next])
                    {
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }

            ans++;
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}