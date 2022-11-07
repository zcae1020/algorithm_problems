#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n,m[128][128],b,w;

bool isEqual(int sx,int ex,int sy,int ey) {
    int a = m[sx][sy];
    for(int i=sx;i<ex;i++)
        for(int j=sy;j<ey;j++)
            if(a!=m[i][j])
                return 0;
    
    return 1;
}

void p(int sx,int sy) {
    if(m[sx][sy]) b++;
    else w++;
}

void getPaper(int sx,int ex,int sy,int ey) {
    if(isEqual(sx,ex,sy,ey)) {
        p(sx,sy);
        return;
    }

    getPaper(sx, (sx+ex)/2, sy, (sy+ey)/2);
    getPaper(sx, (sx+ex)/2, (sy+ey)/2, ey);
    getPaper((sx+ex)/2, ex, sy, (sy+ey)/2);
    getPaper((sx+ex)/2, ex, (sy+ey)/2, ey);
} 

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }

    getPaper(0,n,0,n);

    cout<<w<<'\n'<<b;
}

int main() {
    FASTIO
    Solution();
}