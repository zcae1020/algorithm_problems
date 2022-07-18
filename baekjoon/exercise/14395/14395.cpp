#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

typedef struct qs
{
    ll num;
    int cnt;
    string str;
} qs;

const int maxn = 1e9 + 10;

int s, t;
unordered_set<int> us;
queue<qs> q;
qs ans = {-1, maxn, string()};

void Solution()
{
    cin >> s >> t;
    if (s == t)
    {
        cout << 0;
        return;
    }

    q.push({s, 0, string()});
    us.insert(s);
    while (q.size())
    {
        qs cur = q.front();
        q.pop();

        if (cur.num == t && cur.cnt < ans.cnt)
            ans = cur;

        if (us.count(cur.num * cur.num) == 0 && cur.num * cur.num < 1e9 + 10)
        {
            string tmp = cur.str;
            tmp.push_back('*');
            q.push({cur.num * cur.num, cur.cnt + 1, tmp});
            us.insert(cur.num * cur.num);
        }
        if (us.count(cur.num * 2) == 0 && cur.num * 2 < 1e9 + 10)
        {
            string tmp = cur.str;
            tmp.push_back('+');
            q.push({cur.num * 2, cur.cnt + 1, tmp});
            us.insert(cur.num * 2);
        }
        if (us.count(0) == 0)
        {
            string tmp = cur.str;
            tmp.push_back('-');
            us.insert(0);
        }
        if (us.count(1) == 0)
        {
            string tmp = cur.str;
            tmp.push_back('/');
            q.push({1, cur.cnt + 1, tmp});
            us.insert(1);
        }
    }

    if (ans.num == -1)
        cout << -1;
    else
        cout << ans.str;
}

int main()
{
    FASTIO
    Solution();
}