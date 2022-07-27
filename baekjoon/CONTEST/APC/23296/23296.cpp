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
jfdslfsd
void dfs(int cur)
{
    ans.push_back(cur);

    if (indeg[A[cur]])
    {
        indeg[A[cur]]--;
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

    for (int i = 1; i <= N; i++)
        if (!indeg[i])
            z.push_back(i);

    if (z.size())
        for (auto i : z)
            dfs(i);
    else
        for (int i = 1; i <= N; i++)
            if (indeg[i])
                dfs(i);

    if (ans.front() == 1)
        ans.erase(ans.begin());
    cout << ans.size() << '\n';
    for (auto a : ans)
        cout << a << ' ';
}

int main()
{
    FASTIO
    Solution();
}