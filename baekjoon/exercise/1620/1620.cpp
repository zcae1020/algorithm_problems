#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

unordered_map<int, string> ntop;
unordered_map<string, int> pton;
int n, m;

void Solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        ntop[i] = t;
        pton[t] = i;
    }
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        if ('1' <= t.front() && t.front() <= '9')
            cout << ntop[stoi(t)];
        else
            cout << pton[t];
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}