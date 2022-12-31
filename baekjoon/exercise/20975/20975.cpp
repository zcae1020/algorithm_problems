#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, a[20], b[20];

ll ans = 1;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);

    for (int i = n - 1, j = 0; i > 0; i--, j++)
    {
        int cnt = 0;
        for (int k = 0; k < n; k++)
        {
            if (a[i] <= b[k])
            {
                cnt++;
            }
        }

        ans *= (cnt - j);
    }

    cout << (ans < 1 ? 0 : ans);
}

int main()
{
    FASTIO
    Solution();
}