#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

bool check(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

void Solution()
{
    vector<string> v;
    int n;
    bool isPL = false;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        v.push_back(a);
        if (check(a))
            isPL = true;
    }

    if (isPL)
    {
        cout << "YES\n";
        return;
    }

    set<string> ss2, ss22, ss3;

    for (int i = 0; i < v.size(); i++)
    {
        string s;

        if (v[i].size() == 2)
        {
            if (ss2.count(v[i]))
            {
                isPL = true;
                break;
            }

            s = v[i];
            reverse(s.begin(), s.end());
            ss2.insert(s);
            ss22.insert(s);
        }
        else
        {
            if (ss22.count(v[i].substr(1, 2)))
            {
                isPL = true;
                break;
            }
            if (ss3.count(v[i]))
            {
                isPL = true;
                break;
            }

            s = v[i].substr(0, 2);
            reverse(s.begin(), s.end());
            ss2.insert(s);

            s = v[i];
            reverse(s.begin(), s.end());
            ss3.insert(s);
        }
    }

    if (isPL)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}