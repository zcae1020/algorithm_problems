#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t, m, n, x, y;

void Solution()
{
    cin >> t;

    while (t--)
    {
        cin >> m >> n >> x >> y;

        x = (x == m ? 0 : x);
        y = (y == n ? 0 : y);

        for (int i = 0;; i++)
        {
            if (i == 0 && x == 0 && y == 0)
            {
                continue;
            }

            int num = m * i + x;
            if (num > m * n)
            {
                cout << -1 << '\n';
                break;
            }
            if (num % n == y)
            {
                cout << num << '\n';
                break;
            }
        }
    }
}

int main()
{
    FASTIO
    Solution();
}