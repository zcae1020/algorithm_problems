#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n;
vector<string> v;

void makeDe(int cnt, int previous, string s)
{
    if (cnt == 0)
    {
        v.push_back(s);
        return;
    }

    if (!previous)
        return;

    for (int i = 0; i < previous; i++)
    {
        s.push_back(i + '0');
        makeDe(cnt - 1, i, s);
        s.pop_back();
    }
}

void Solution()
{
    for (int i = 1; i <= 10; i++)
        makeDe(i, 10, string());

    cin >> n;

    if (n < v.size())
        cout << v[n];
    else
        cout << -1;
}

int main()
{
    FASTIO
    Solution();
}