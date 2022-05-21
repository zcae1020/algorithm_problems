#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
set<int> s;
map<int, int> m;

void Input()
{
    s.clear();
    m.clear();

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (s.count(a))
            m[a]++;
        else
        {
            s.insert(a);
            m.insert({a, 1});
        }
    }
}

void Solution()
{
    vector<pair<int, int>> v;
    v.resize(s.size());

    int idx = 0, mx = -1, mxIdx = -1;
    for (auto a : s)
    {
        if (!idx)
        {
            if (m[a] >= k)
                v[idx] = {a, 1};
            else
                v[idx] = {a, 0};
        }
        else
        {
            if (m[a] >= k)
            {
                if (v[idx - 1].first + 1 == a)
                    v[idx] = {a, v[idx - 1].second + 1};
                else
                    v[idx] = {a, 1};
            }
            else
                v[idx] = {a, 0};
        }

        if (mx < v[idx].second)
        {
            mx = v[idx].second;
            mxIdx = idx;
        }

        idx++;
    }

    if (mx <= 0)
        cout << -1 << '\n';
    else if (mx == 1)
        cout << v[mxIdx].first << ' ' << v[mxIdx].first << '\n';
    else // mx > 1
    {
        int l = -1, r = v[mxIdx].first;
        for (int i = mxIdx - 1; i >= 0; i--)
        {
            if (v[i].second == 1)
            {
                l = v[i].first;
                break;
            }
        }
        cout << l << ' ' << r << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        Input();
        Solution();
    }
}