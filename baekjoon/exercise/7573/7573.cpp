#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 10;

int N, I, M, ans = 1;
vector<pii> v;

void Solution()
{
    cin >> N >> I >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int h = 1, w = I / 2 - 1; h < I / 2; h++, w--)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int cx = v[i].x, cy = v[i].y;
            if (cx + h > N)
                break;
            for (int sy = cy - w, ey = cy; sy <= cy; sy++, ey++)
            {
                if (sy < 1 || ey > N)
                    continue;

                int cnt = 1;
                for (int j = i + 1; j < v.size(); j++)
                    if (cx <= v[j].x && v[j].x <= cx + h && sy <= v[j].y && v[j].y <= ey)
                        cnt++;

                ans = max(ans, cnt);
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