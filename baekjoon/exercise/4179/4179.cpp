#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e3+ 10;

int R,C;
string MAP[maxn];
pii start;
vector<pii> fire;
queue<pair<pii, pii>> q;
bool visited[maxn][maxn][2];

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool isInMap(pii p) {
    return p.fs>=0&&p.sd>=0&&p.fs<R&&p.sd<C;
}

int bfs() {
    for(auto f:fire) {
        q.push({f, {1,1}});
        visited[f.fs][f.sd][1] = 1;
    }

    q.push({start, {1, 0}});
    visited[start.fs][start.sd][0] = 1;

    while(!q.empty()) {
        pii cur = q.front().fs;
        int cnt = q.front().sd.fs;
        int type = q.front().sd.sd;
        q.pop();

        if(type == 0 && (cur.fs == 0 || cur.fs == R - 1 || cur.sd == 0 || cur.sd == C - 1)) {
            return cnt;
        }

        for(int i=0;i<4;i++) {
            pii next = {cur.fs+dx[i], cur.sd+dy[i]};
            
            if(isInMap(next) && MAP[next.fs][next.sd] == '.' && !visited[next.fs][next.sd][type]) {
                if(type) {
                    MAP[next.fs][next.sd] = 'F';
                }
                visited[next.fs][next.sd][type] = 1;
                q.push({next, {cnt+1, type}});
            }
        }
    }

    return 0;
}

void Solution() {
    cin>>R>>C;
    for(int i=0;i<R;i++) {
        cin>>MAP[i];
        for(int j=0;j<C;j++) {
            if(MAP[i][j] == 'J') {
                start = {i,j};
            }
            if(MAP[i][j] == 'F') {
                fire.push_back({i,j});
            }
        }
    }

    int ans;
    if(ans = bfs()) {
        cout<<ans;
    }
    else {
        cout<<"IMPOSSIBLE";
    }
}

int main() {
    FASTIO
    Solution();
}