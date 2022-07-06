#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, ans;
vector<pii> v;
priority_queue<int> q;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        while (q.size() && -q.top() <= v[i].first)
            q.pop();
        q.push(-v[i].second);
        ans = max(ans, (int)q.size());
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}