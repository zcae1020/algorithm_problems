#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
#define x first
#define y second

using namespace std;

const ull maxn = 1e18;

ull p[3], input;
set<ull> s;

void Solution()
{
    for (int i = 0; i < 3; i++)
        cin >> p[i];
    cin >> input;

    for (int i = 0; i < 3; i++)
    {
        for (ull cur = p[i]; cur <= 1e18; cur *= p[i])
        {
            for (auto n : s)
            {
                if (n * cur <= 1e18)
                    s.insert(n * cur);
            }
            s.insert(cur);
        }
    }

    for (auto n : s)
    {
        if (--input == 0)
        {
            cout << n;
            break;
        }
    }
}

int main()
{
    FASTIO
    Solution();
}