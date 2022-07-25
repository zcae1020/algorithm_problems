#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int tc;
string s;
stack<char> s1, s2;

void Solution()
{
    cin >> tc;
    while (tc--)
    {
        cin >> s;
        for (auto c : s)
        {
            switch (c)
            {
            case '-':
                if (s1.size())
                    s1.pop();
                break;
            case '<':
                if (s1.size())
                    s2.push(s1.top()), s1.pop();
                break;
            case '>':
                if (s2.size())
                    s1.push(s2.top()), s2.pop();
                break;
            default:
                s1.push(c);
                break;
            }
        }

        vector<char> v;
        while (s1.size())
            v.push_back(s1.top()), s1.pop();
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i];
        while (s2.size())
            cout << s2.top(), s2.pop();
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}