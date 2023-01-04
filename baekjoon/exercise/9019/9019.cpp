#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

vector<string> ans;

int Dop(int a)
{
    return a * 2 % 10000;
}

int Sop(int a)
{
    return (a == 0 ? 9999 : a - 1);
}

int Lop(int a)
{
    return ((a % 1000) * 10 + a / 1000);
}

int Rop(int a)
{
    return ((a / 10) + (a % 10) * 1000);
}

pair<int, string> oper(int idx, int num)
{
    switch (idx)
    {
    case 0:
        return {Dop(num), "D"};
    case 1:
        return {Sop(num), "S"};
    case 2:
        return {Lop(num), "L"};
    case 3:
        return {Rop(num), "R"};
    }
}

void bfs(int a, int b)
{
    ans.clear();
    queue<pair<int, string>> q;
    bool visited[10000] = {false};
    q.push({a, ""});
    visited[a] = true;

    while (!q.empty())
    {
        int cur = q.front().fs;
        string op = q.front().sd;
        q.pop();

        if (!ans.empty() && op.size() == ans.front().size())
        {
            cout << ans.front() << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            pair<int, string> next = oper(i, cur);
            if (next.fs == b)
            {
                ans.push_back(op + next.sd);
            }
            if (!visited[next.fs])
            {
                visited[next.fs] = true;
                q.push({next.fs, op + next.sd});
            }
        }
    }
}

void Solution()
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        bfs(a, b);
    }
}

int main()
{
    FASTIO
    Solution();
}