#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, a, b, ans = 1;

void Solution()
{
    cin >> n >> a >> b;

    int tmp = min(a, b);
    b = max(a, b);
    a = tmp;

    while (a + 1 != b || a % 2 == 0)
    {
        ans++;

        n = n / 2 + n % 2;
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
    }

    cout << ans << "\n";
}

int main()
{
    FASTIO
    Solution();
}