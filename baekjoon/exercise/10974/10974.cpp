#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n;
vector<int> v;
bool visited[9];

void dfs()
{
    if (v.size() == n)
    {
        for (auto a : v)
            cout << a << ' ';
        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            v.push_back(i);
            visited[i] = 1;
            dfs();
            visited[i] = 0;
            v.pop_back();
        }
    }
}

void Solution()
{
    cin >> n;
    dfs();
}

int main()
{
    FASTIO
    Solution();
}