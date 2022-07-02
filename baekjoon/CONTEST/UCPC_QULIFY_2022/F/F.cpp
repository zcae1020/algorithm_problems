#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m, s, c = 1e6;
string MAP[55], id;
vector<pii> v[26];
vector<char> be;
int need[26], level;

void dfs(pii cur, int idx)
{
    if (idx == id.size())
    {
        level++;
        idx = 0;
    }
    if (level == c)
    {
        for (int i = cur.first + 1; i < n; i++)
            be.push_back('D');
        for (int i = cur.second + 1; i < m; i++)
            be.push_back('R');
        return;
    }

    pii next = v[id[idx] - 'a'].front();
    v[id[idx] - 'a'].erase(v[id[idx] - 'a'].begin());

    if (cur.first > next.first)
        for (int i = next.first; i < cur.first; i++)
            be.push_back('U');
    else
        for (int i = cur.first; i < next.first; i++)
            be.push_back('D');

    if (cur.second > next.second)
        for (int i = next.second; i < cur.second; i++)
            be.push_back('L');
    else
        for (int i = cur.second; i < next.second; i++)
            be.push_back('R');

    be.push_back('P');

    dfs(next, idx + 1);
}

void Solution()
{
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> MAP[i];
        for (int j = 0; j < m; j++)
        {
            v[MAP[i][j] - 'a'].push_back(pii(i, j));
        }
    }

    cin >> id;

    for (auto a : id)
        need[a - 'a']++;

    for (int i = 0; i < 26; i++)
        if (need[i])
            c = min(c, (int)v[i].size() / need[i]);

    dfs(pii(0, 0), 0);

    cout << c << ' ' << be.size() << '\n';
    for (auto a : be)
        cout << a;
}

int main()
{
    FASTIO
    Solution();
}