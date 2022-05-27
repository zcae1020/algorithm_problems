#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#define pii pair<int, int>

using namespace std;

const int MAX = 2e5 + 10;

int n, par[MAX], indegree[MAX];
pii bwnum[MAX];
queue<int> leaf;
string bw;

void Input()
{
    cin >> n;

    memset(indegree, 0, sizeof(indegree));
    memset(par, 0, sizeof(par));
    memset(bwnum, 0, sizeof(bwnum));

    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        par[i];
        indegree[par[i]]++;
    }

    cin >> bw;
    for (int i = 0; i < n; i++)
    {
        if (bw[i] == 'B')
            bwnum[i + 1].first++;
        else
            bwnum[i + 1].second++;
    }
}

void Solution()
{
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            leaf.push(i);
    while (!leaf.empty())
    {
        int cur = leaf.front();
        leaf.pop();

        if (cur == 1)
            break;

        int next = par[cur];
        bwnum[next].first += bwnum[cur].first;
        bwnum[next].second += bwnum[cur].second;

        if (--indegree[next] == 0)
            leaf.push(next);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (bwnum[i].first == bwnum[i].second)
            ans++;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        Input();
        Solution();
    }
}