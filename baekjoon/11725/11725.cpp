#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> ans;
vector<vector<int>> v;

void Input()
{
    cin >> N;
    ans.resize(N + 1);
    v.resize(N + 1);
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void DFS(int cur, int p)
{
    ans[cur] = p;
    for (auto a : v[cur])
        if (ans[a] == 0)
            DFS(a, cur);
}

void Solution()
{
    DFS(1, 1);
    for (int i = 2; i <= N; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}