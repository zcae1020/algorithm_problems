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
vector<int> ans;
bool visited[maxn];

void dfs(int cur)
{
    visited[cur] = 1;
    ans.push_back(A[cur]);
    if (!visited[A[cur]])
        dfs(A[cur]);
}

void Solution()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        indeg[A[i]]++;
    }

    dfs(1);

    for (int i = 2; i <= N; i++)
        if (!visited[i] && !indeg[i])
            ans.push_back(i), dfs(i);

    for (int i = 2; i <= N; i++)
        if (!visited[i])
            ans.push_back(i), dfs(i);

    cout << ans.size() << '\n';
    for (auto a : ans)
        cout << a << ' ';
}

int main()
{
    FASTIO
    Solution();
}