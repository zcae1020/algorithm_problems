#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int A, B;

void dfs(ll c, int cnt)
{
    if (c > B)
        return;

    if (c == B)
    {
        cout << cnt;
        exit(0);
    }

    dfs(c * 10 + 1, cnt + 1);
    dfs(2 * c, cnt + 1);
}

void Solution()
{
    cin >> A >> B;

    dfs(A, 1);

    cout << -1;
}

int main()
{
    FASTIO
    Solution();
}