#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, k;
ll ans;
priority_queue<int> pq;
vector<pii> jew;
vector<int> bag;

void Solution()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        jew.push_back({a, b});
    }
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        bag.push_back(a);
    }

    sort(jew.begin(), jew.end());
    sort(bag.begin(), bag.end());

    int jidx = 0;
    for (int i = 0; i < k; i++)
    {
        for (; jidx < n && jew[jidx].first <= bag[i]; jidx++)
            pq.push(jew[jidx].second);
        if (pq.size())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}