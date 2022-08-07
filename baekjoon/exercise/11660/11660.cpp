#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 1 << 10 + 1;

int N, M, arr[maxn][maxn], psum[maxn][maxn];

void Solution()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            psum[i][j] = arr[i][j] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
        }

    for (int i = 0; i < M; i++)
    {
        int a, b, c, d, x1, x2, y1, y2;
        cin >> a >> b >> c >> d;
        x1 = min(a, c), x2 = max(a, c), y1 = min(b, d), y2 = max(b, d);
        cout << psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1] << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}