#include <iostream>
#include <vector>

using namespace std;

int N, root, ans, del, arr[50];
vector<vector<int>> edge;

void Input()
{
    cin >> N;
    edge.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == -1)
        {
            root = i;
            continue;
        }
        edge[arr[i]].push_back(i);
    }

    cin >> del;
}

void dfs(int cur)
{
    if (edge[cur].empty())
        ans++;
    for (auto a : edge[cur])
        dfs(a);
}

void Solution()
{
    if (arr[del] == -1)
    {
        cout << 0;
        exit(0);
    }
    else
    {
        for (int i = 0; i < edge[arr[del]].size(); i++)
        {
            if (edge[arr[del]][i] == del)
            {
                edge[arr[del]].erase(edge[arr[del]].begin() + i);
                continue;
            }
        }
    }

    dfs(root);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}