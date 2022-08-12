#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 5e5 + 10;

priority_queue<pii> pq;
int n, arr[maxn], ans[maxn];

void Solution()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = n; i > 0; i--)
    {
        while (pq.size())
        {
            if (-pq.top().first <= arr[i])
            {
                ans[pq.top().second] = i;
                pq.pop();
            }
            else
                break;
        }
        pq.push({-arr[i], i});
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}

int main()
{
    FASTIO
    Solution();
}