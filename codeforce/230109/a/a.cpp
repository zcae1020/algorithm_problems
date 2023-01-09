#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, a, b, c;

void Solution()
{
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        if (a == b + c || b == a + c || c == a + b)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    FASTIO
    Solution();
}