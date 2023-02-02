#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int R,C, ans = INT_MAX;
string M[100];
pii endPoint;

int visited[100][100][4]; // map size * 4방향
queue<pair<pii, pii>> q;

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0}; // 우, 하, 좌, 상 

bool validate(pii p, int cnt, int di) {
    return p.fs >= 0 && p.sd >= 0 && p.fs < R && p.sd < C 
    && M[p.fs][p.sd] != '*' && (visited[p.fs][p.sd][di] == -1 || cnt < visited[p.fs][p.sd][di]);
}

void Solution() {
    memset(visited, -1, sizeof(visited));

    cin>>C>>R;

    for(int i=0;i<R;i++) {
        cin>>M[i];
        for(int j=0;j<C;j++) {
            if(M[i][j] == 'C') {
                endPoint = {i,j};
            }
        }
    }

    for(int i=0;i<4;i++) {
        visited[endPoint.fs][endPoint.sd][i] = 0;
        pii next = {endPoint.fs + dx[i], endPoint.sd + dy[i]};
        if(validate(next, 0, i)) {
            q.push({next,{0,i}});
            visited[next.fs][next.sd][i] = 0;
        }
    }
    
    while(!q.empty()) {
        pii cur = q.front().fs;
        int cnt = q.front().sd.fs;
        int di = q.front().sd.sd;
        q.pop();

        if(M[cur.fs][cur.sd] == 'C') {
            ans = min(ans, cnt);
            continue;
        }

        for(int i=0;i<4;i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};
            if((di+2)%4 == i) {
                continue;
            } 

            if(i == di) {
                if(validate(next, cnt, i)) {
                    q.push({next,{cnt,i}});
                    visited[next.fs][next.sd][i] = cnt;
                }
            }
            else {
                if(validate(next, cnt + 1, i)) {
                    q.push({next,{cnt + 1,i}});
                    visited[next.fs][next.sd][i] = cnt + 1;
                }
            }
        }
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}