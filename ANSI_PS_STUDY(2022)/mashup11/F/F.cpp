#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

void Solution()
{
    set<string> s1, s2;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        s1.insert(a);
    }

    for (auto a : s1)
    {
        reverse(a.begin(), a.end());
        s2.insert(a);
        if (a.size() < 3)
            for (char c = 'a'; c <= 'z'; c++)
                s2.insert(c + a);
    }

    for (auto a : s1)
    {
        if (s2.count(a))
        {
            cout << "YES\n";
            return;
        }
    }

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


// 7
// 5
// zx
// ab
// cc
// zx
// ba
// 2
// ab
// bad
// 4
// co
// def
// orc
// es
// 3
// a
// b
// c
// 3
// ab
// cd
// cba
// 2
// ab
// ab
// 5
// zab
// cdd
// cb
// az
// bz