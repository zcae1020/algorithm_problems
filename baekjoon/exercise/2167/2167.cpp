#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, k, arr[301][301];
ll psum[301][301];

void Solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            psum[i][j] = arr[i][j] - psum[i - 1][j - 1] + psum[i - 1][j] + psum[i][j - 1];
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << psum[c][d] - psum[a - 1][d] - psum[c][b - 1] + psum[a - 1][b - 1] << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}