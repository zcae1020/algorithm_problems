#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int N, I, M, m[10001][10001];
vector<pii> v;

int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, 1, -1};

void Solution()
{
    cin >> N >> I >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a][b]++;
        for(int )
    }

    for (auto p : v)
    {
        for (int i = 1; i < I / 2; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int maxx = p.x + dx[j] * i, maxy = p.y + dy[j] * (I / 2 - i);
                if (maxx <= N && maxx > 0 && maxy <= N && maxy > 0)
                {
                    int cnt = 0;
                    for (int x = p.x; (dx[j] > 0 && x <= maxx) || (dx[j] < 0 && x >= maxx); x += dx[j])
                        for (int y = p.y; (dy[j] > 0 && y <= maxy) || (dy[j] < 0 && y >= maxy); y += dy[j])
                            if (m[x][y])
                                cnt++;
                    ans = max(ans, cnt);
                }
            }
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}