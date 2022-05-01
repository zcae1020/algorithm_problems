#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define pii pair<int, int>

using namespace std;

int N, ans, jump;
vector<pii> v, t;

void Input()
{
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
}

void getTie()
{
    sort(v.begin(), v.end(), less<pii>());
    int s = v[0].first, e = v[0].second;
    for (int i = 1; i < v.size(); i++)
    {
        if (e >= v[i].first)
            e = max(e, v[i].second);
        else
        {
            t.push_back({s, e});
            s = v[i].first, e = v[i].second;
        }
    }
    t.push_back({s, e});
}

void Solution()
{
    getTie();
    for (int i = 0; i < t.size(); i++)
    {
        if (jump >= t[i].first)
        {
            ans = max(ans, t[i].second);
            jump = max(jump, t[i].second + t[i].second - t[i].first);
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}