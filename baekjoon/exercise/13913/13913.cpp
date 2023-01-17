#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int a, b;
int dx[] = {-1, 1};
int visited[100001];
queue<int> q;
vector<int> ans;

void dfs(int i) {
    if(i==-2) {
        return; 
    }
    ans.push_back(i);
    dfs(visited[i]);
}

void Solution()
{
    cin >> a >> b;
    memset(visited, -1, sizeof(visited));
    visited[a] = -2;
    q.push(a);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur == b) {
            dfs(cur);
            cout<<ans.size()-1<<'\n';
            for(int i=ans.size()-1;i>=0;i--) {
                cout<<ans[i]<<' ';
            }
            return;
        }

        int next = 2 * cur;
        if (next >= 0 && next <= 1e5 && visited[next]== -1)
        {
            q.push(next);
            visited[next] = cur;
        }

        for (int i = 0; i < 2; i++)
        {
            int next = cur + dx[i];
            if (next >= 0 && next <= 1e5 && visited[next]==-1)
            {
                q.push(next);
                visited[next] = cur;
            }
        }
    }
}

int main()
{
    FASTIO
    Solution();
}