#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, ans;
vector<int> expect;
vector<vector<int>> tree;
vector<bool> visited;

void Input()
{
    cin >> N;
    expect.resize(N);
    visited.resize(N);
    tree.resize(N);

    for (int i = 0; i < N; i++)
        cin >> expect[i];
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void DFS(int cur, int c)
{
    visited[cur] = 1;

    if (expect[cur] != c)
    {
        ans++;
        c = expect[cur];
    }

    for (auto next : tree[cur])
        if (!visited[next])
            DFS(next, c);
}

void Solution()
{
    DFS(0, 0);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}