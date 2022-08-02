#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, a[10004], sum, mx;
bool p;

bool isAns(int dist, int start, int need)
{
    bool changeStart = false;
    int s = start, e = start + 1, su = a[start], cnt = 0;

    while (e != start)
    {
        if (dist == su)
        {
            if (!changeStart)
            {
                start = e;
                changeStart = true;
            }
            cnt++;
            s = e;
            su = 0;
        }
        else if (dist < su)
        {
            su -= a[s];
            s = (s + 1) % n;
        }
        else
        {
            su += a[e];
            e = (e + 1) % n;
        }
    }

    return cnt == need;
}

void Solution()
{
    while (1)
    {
        sum = 0, mx = 0, p = 0;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }

        for (int i = n; i > 2; i--)
        {
            if (sum % i == 0 && sum / i >= mx)
            {
                if (isAns(sum / i, 0, i))
                {
                    p = 1;
                    cout << n - i;
                    break;
                }
            }
        }
        if (!p)
            cout << -1;
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}