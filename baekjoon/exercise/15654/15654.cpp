#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m;
vector<int> v;
bool visited[8];

void dfs(vector<int> a)
{
    if (a.size() == m)
    {
        for (auto aa : a)
            cout << aa << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            a.push_back(v[i]);
            visited[i] = 1;
            dfs(a);
            a.pop_back();
            visited[i] = 0;
        }
    }
}

void Solution()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    dfs(vector<int>());
}

int main()
{
    FASTIO
    Solution();
}