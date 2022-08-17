#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

string str;
stack<pair<char, int>> s;
int ans, n;

void Solution()
{
    cin >> str;

    for (auto c : str)
    {
        n = 0;

        if (c == ')')
        {
            if (s.empty() || s.top().first != '(')
            {
                ans = 0;
                break;
            }

            n = s.top().second ? s.top().second * 2 : 2;
            s.pop();
        }
        else if (c == ']')
        {
            if (s.empty() || s.top().first != '[')
            {
                ans = 0;
                break;
            }

            n = s.top().second ? s.top().second * 3 : 3;
            s.pop();
        }
        else
            s.push({c, 0});

        if (s.empty())
            ans += n;
        else
            s.top().second += n;
    }

    if (s.size())
        ans = 0;

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}