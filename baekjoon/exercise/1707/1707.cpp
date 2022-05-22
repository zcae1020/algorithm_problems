#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int k, v, e;
vector<vector<int>> edge;
vector<int> color;

void Input()
{
    cin >> v >> e;
    edge.clear();
    color.clear();
    edge.resize(v + 1);
    color.resize(v + 1);
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto next : edge[cur])
        {
            if (color[next] == 0)
            {
                q.push(next);
                color[next] = (color[cur] == 1 ? 2 : 1);
            }
        }
    }
}

bool isBinaryGraph()
{
    for (int i = 1; i <= v; i++)
        for (auto a : edge[i])
            if (color[i] == color[a])
                return false;
    return true;
}

void Solution()
{
    for (int i = 1; i <= v; i++)
        if (!color[i])
            bfs(i);

    if (isBinaryGraph())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> k;
    while (k--)
    {
        Input();
        Solution();
    }
}