#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, arr[2000], ans = 2e5;
bool isZero = true;
set<int> s, ot;
map<int, int> m;

bool check()
{
    for (auto a : ot)
        if (m[a] > 1)
            return false;
    return true;
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
        m[arr[i]]++;
    }

    for (auto a : s)
        if (m[a] > 1)
            ot.insert(a), isZero = false;

    if (isZero)
    {
        cout << 0;
        return;
    }

    int l, r;
    l = r = 0;

    while (r <= n)
    {
        if (check())
        {
            ans = min(ans, r - l);
            m[arr[l++]]++;
        }
        else
            m[arr[r++]]--;
    }
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}