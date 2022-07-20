#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int A, B, N, cnt, t0mx, t1mx;
vector<int> ans[2];
priority_queue<pii> pq;

void Solution()
{
    cin >> A >> B >> N;
    for (int i = 0; i < N; i++)
    {
        int a, c, s;
        char b;
        cin >> a >> b >> c;

        if (b == 'B')
        {
            s = max(t0mx, a);
            for (int j = 0; j < c; j++)
                pq.push({-(s + A * j), 1});
            t0mx = s + A * c;
        }
        else
        {
            s = max(t1mx, a);
            for (int j = 0; j < c; j++)
                pq.push({-(s + B * j), 0});
            t1mx = s + B * c;
        }
    }

    while (pq.size())
    {
        pii cur = pq.top();
        pq.pop();
        cnt++;

        if (cur.second)
            ans[0].push_back(cnt);
        else
            ans[1].push_back(cnt);
    }

    for (int i = 0; i < 2; i++)
    {
        cout << ans[i].size() << '\n';
        for (auto e : ans[i])
            cout << e << ' ';
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}