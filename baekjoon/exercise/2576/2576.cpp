#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int a, s, m = 100;

void Solution()
{
    for (int i = 0; i < 7; i++)
    {
        cin >> a;
        if (a % 2)
            s += a, m = min(m, a);
    }

    if (m == 100)
        cout << -1;
    else
        cout << s << '\n'
             << m;
}

int main()
{
    FASTIO
    Solution();
}