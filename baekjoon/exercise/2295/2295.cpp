#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, a[1000];
unordered_map<long long, bool> m;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[a[i] + a[j]] = 1;

    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            if (m[a[i] - a[j]])
            {
                cout << a[i];
                return;
            }
}

int main()
{
    FASTIO
    Solution();
}