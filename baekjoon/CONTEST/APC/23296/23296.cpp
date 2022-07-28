#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 1e5 + 10;

int N, A[maxn], indeg[maxn];
vector<int> ans, z;
bool visited[maxn];
fjsdlkajf
void dfs(int cur)
{
    ans.push_back(cur);

    if (!visited[cur])
    {
        visited[cur] = 1;
        dfs(A[cur]);
    }
}

void Solution()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        indeg[A[i]]++;
    }

    visited[1] = 1;
    dfs(A[1]);

    for (int i = 2; i <= N; i++)
        if (!indeg[i])
            z.push_back(i);

    for (int i = 1; i <= N; i++)
        if (!visited[i])
            dfs(i);

    cout << ans.size() << '\n';
    for (auto a : ans)
        cout << a << ' ';
}

int main()
{
    FASTIO
    Solution();
}