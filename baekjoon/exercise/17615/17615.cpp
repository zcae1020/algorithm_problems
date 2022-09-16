#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, R, B, f, b, ans;
string s;

void Solution()
{
    cin >> N >> s;
    for (auto c : s)
    {
        if (c == 'R')
            R++;
        else if (c == 'B')
            B++;
    }

    for (int i = 1; i < s.size(); i++)
    {
        if (s.front() != s[i])
        {
            f = i;
            break;
        }
    }

    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (s.back() != s[i])
        {
            b = s.size() - i - 1;
            break;
        }
    }

    if (s.front() != s.back())
        ans = (s.front() == 'R') ? min(R - f, B - b) : min(R - b, B - f);
    else
        ans = (s.front() == 'R') ? min(B, R - max(f, b)) : min(R, B - max(f, b));

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}