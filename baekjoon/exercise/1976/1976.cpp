#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int N, M, plan[1000];
bool edge[201][201];

void bfs(int s)
{
    bool v[201] = {0};
    queue<int> q;
    q.push(s);

    while (q.size())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (!v[i] && edge[cur][i]){
                v[i] = edge[s][i] = edge[i][s] = 1;
                q.push(i);
            }
        }
    }
}

void Solution()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> edge[i][j];
    for (int i = 0; i < M; i++)
        cin >> plan[i];

    for (int i = 1; i <= N; i++){
        edge[i][i] = 1;
        bfs(i);
    }

    bool ans = true;
    for (int i = 0; i < M - 1; i++)
    {
        if (!edge[plan[i]][plan[i + 1]])
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO");
}

int main()
{
    FASTIO
    Solution();
}