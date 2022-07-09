#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m;
unordered_set<string> s;
vector<string> v;

void Solution()
{
    cin >> n >> m;
    while (n--)
    {
        string x;
        cin >> x;
        s.insert(x);
    }

    while (m--)
    {
        string x;
        cin >> x;
        if (s.count(x))
            v.push_back(x);
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for (auto a : v)
        cout << a << '\n';
}

int main()
{
    FASTIO
    Solution();
}