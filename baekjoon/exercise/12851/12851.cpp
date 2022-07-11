#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxs = 1e5 + 10;

fjdsksafd
//nonsolve

int visited[maxs], n, k, T = maxs, cnt;
queue<pii> q;



void Solution()
{
    cin >> n >> k;
    q.push({n, 0});
    while (q.size())
    {
        int c = q.front().first;
        int t = q.front().second;
        q.pop();

        if (c == k)
        {
            if (T == t)
                cnt++;
            else if (t < T)
            {
                T = t;
                cnt = 1;
            }
            continue;
        }

        if (T < t || c < 0 || c >= maxs || visited[c])
            continue;

        visited[c] = 1;
        q.push({c + 1, t + 1});
        q.push({c - 1, t + 1});
        q.push({2 * c, t + 1});
    }

    cout << T << '\n'
         << cnt;
}

int main()
{
    FASTIO
    Solution();
}