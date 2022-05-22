#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;
vector<vector<int>> v;
vector<bool> isCycle, visit;
vector<int> pre, ans, cycle;

void Input()
{
    cin >> N;
    v.resize(N);
    pre.resize(N);
    ans.resize(N);
    isCycle.resize(N);
    visit.resize(N);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
}

void findCycle(int cur)
{
    visit[cur] = true;
    for (auto next : v[cur])
    {
        if (!cycle.empty())
            return;
        if (visit[next])
        {
            if (pre[cur] != next)
            {
                while (pre[cur] != next)
                {
                    isCycle[cur] = true;
                    cycle.push_back(cur);
                    cur = pre[cur];
                }
                isCycle[cur] = true;
                isCycle[next] = true;
                cycle.push_back(cur);
                cycle.push_back(next);
            }
        }
        else
        {
            pre[next] = cur;
            findCycle(next);
        }
    }
}

void getAns()
{
    queue<int> q;
    visit.clear(), visit.resize(N);

    for (auto a : cycle)
        q.push(a);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto a : v[cur])
        {
            if (!isCycle[a] && !visit[a])
            {
                visit[a] = true;
                ans[a] = ans[cur] + 1;
                q.push(a);
            }
        }
    }
}

void Solution()
{
    findCycle(0);
    getAns();
    for (int i = 0; i < N; i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}