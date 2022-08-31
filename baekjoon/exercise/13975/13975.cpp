#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int T, K;

void Solution()
{
    cin >> T;
    while (T--)
    {
        priority_queue<ll> pq;
        ll x1, x2, ans = 0;

        cin >> K;

        for (int i = 0; i < K; i++)
        {
            cin >> x1;
            pq.push(-x1);
        }

        while (pq.size() > 1)
        {
            x1 = -pq.top();
            pq.pop();
            x2 = -pq.top();
            pq.pop();

            ans += x1 + x2;
            pq.push(-(x1 + x2));
        }

        cout << ans << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}