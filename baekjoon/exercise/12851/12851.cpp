#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxs = 1e5 + 10;

int n, k, tans = maxs, cnt, visited[maxs];
queue<pii> q;

int dx[3] = {-1, 1, 0};

void Solution()
{
    cin >> n >> k;

    q.push({n, 1});
    visited[n] = 1;
    while (q.size())
    {
        int c = q.front().first;
        int t = q.front().second;
        q.pop();

        if (tans < t)
            break;

        if (c == k)
        {
            tans = min(tans, t);
            cnt++;
            continue;
        }

        int next;
        for (int i = 0; i < 3; i++)
        {
            next = c + dx[i];
            if (i == 2)
                next = 2 * c;
            if (0 <= next && next < maxs && (!visited[next] || visited[next] >= t + 1))
            {
                q.push({next, t + 1});
                visited[next] = t + 1;
            }
        }
    }

    cout << tans - 1 << '\n'
         << cnt;
}

int main()
{
    FASTIO
    Solution();
}