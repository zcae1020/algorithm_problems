#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

using namespace std;

const int MAX = 3e5;

int n, cnt[MAX];
vector<int> v, over;
set<int> s;

void Input()
{
    s.clear();
    v.clear();
    over.clear();
    memset(cnt, 0, sizeof(cnt));

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
        s.insert(a);
    }
}

bool can(int m)
{
    int sum = 0;
    for (auto a : over)
        if (a > m)
            sum += (a - m);
    return sum <= m;
}

void Solution()
{
    v.push_back(1);
    for (auto a : s)
        v.push_back(cnt[a]);

    sort(v.begin(), v.end(), greater<>());

    int ans = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        v[i] -= (v.size() - i);
        if (v[i] > 0)
            over.push_back(v[i]);
    }

    if (!over.empty())
    {
        int l = 1, r = MAX, pans = MAX, m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (can(m))
            {
                pans = min(pans, m);
                r = m - 1;
            }
            else
                l = m + 1;
        }
        ans += pans;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        Input();
        Solution();
    }
}