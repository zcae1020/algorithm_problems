#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 2e5 + 10;

long long n, a[MAX], b[MAX], ans, a1, a2, b1, b2, ai1, ai2, bi1, bi2;

void Input()
{
    a1 = a2 = b1 = b2 = 1e9;
    ai1 = ai2 = bi1 = bi2 = -1;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
}

void Solution()
{
    ans = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
    ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    for (int i = 0; i < n; i++)
    {
        a1 = min(a1, abs(a[0] - b[i]));
        a2 = min(a2, abs(a[n - 1] - b[i]));
        b1 = min(b1, abs(a[i] - b[0]));
        b2 = min(b2, abs(a[i] - b[n - 1]));
    }
    ans = min(ans, a1 + b1 + abs(a[n - 1] - b[n - 1]));
    ans = min(ans, a1 + b2 + abs(a[n - 1] - b[0]));
    ans = min(ans, a2 + b1 + abs(a[0] - b[n - 1]));
    ans = min(ans, a2 + b2 + abs(a[0] - b[0]));
    ans = min(ans, a1 + a2 + b1 + b2);
    cout << ans << '\n';
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