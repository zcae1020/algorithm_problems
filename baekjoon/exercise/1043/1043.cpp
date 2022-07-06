#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m, ans;
int tpn, tpa[50];
bool isTrue[51];

vector<vector<int>> party;
unordered_set<int> s[51];
queue<int> q;

void Solution()
{
    cin >> n >> m;
    ans = m;

    cin >> tpn;
    for (int i = 0; i < tpn; i++)
    {
        cin >> tpa[i];
        isTrue[tpa[i]] = 1;
        q.push(tpa[i]);
    }

    for (int a, b, i = 0; i < m; i++)
    {
        cin >> a;
        vector<int> tmp;
        for (int i = 0; i < a; i++)
        {
            cin >> b;
            tmp.push_back(b);
        }

        party.push_back(tmp);

        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < j; k++)
                s[tmp[j]].insert(tmp[k]);
            for (int k = j + 1; k < a; k++)
                s[tmp[j]].insert(tmp[k]);
        }
    }

    while (q.size())
    {
        int cur = q.front();
        q.pop();

        for (auto a : s[cur])
        {
            if (isTrue[a])
                continue;
            isTrue[a] = 1;
            q.push(a);
        }
    }

    for (int i = 0; i < party.size(); i++)
        for (auto a : party[i])
            if (isTrue[a])
            {
                ans--;
                break;
            }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}