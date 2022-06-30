#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int t;
string s;

void Solution()
{
    regex re("(100+1+|01)+");
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (regex_match(s, re))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    FASTIO
    Solution();
}