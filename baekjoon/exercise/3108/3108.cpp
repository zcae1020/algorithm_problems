#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, par[1001], ans;
pair<pii,pii> arr[1001];
bool zz;

bool isCross(int u, int v){
    int ux1,ux2,uy1,uy2,vx1,vx2,vy1,vy2;
    tie(ux1,uy1) = arr[u].first;
    tie(ux2,uy2) = arr[u].second;
    tie(vx1,vy1) = arr[v].first;
    tie(vx2,vy2) = arr[v].second;
    return (ux1<=vx1&&vx1<=ux2&&uy1<=vy1&&vy1<=uy2)!=(vx2<ux1||ux2<vx2||vy2<uy1||uy2<vy2);

}

int find(int u){
    return u==par[u]?par[u]:par[u] = find(par[u]);
}

int merge(int u, int v){
    if(!isCross(u,v)) return 0;

    u = find(u), v = find(v);
    if(u==v) return 0;
    par[u] = v;
    return 1;
}

void Solution() {
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,d,x1,x2,y1,y2;
        par[i]=i;
        cin>>a>>b>>c>>d;
        x1 = min(a,c),x2 = max(a,c),y1 = min(b,d),y2=max(b,d);
        arr[i] = pair<pii,pii>(pii(x1,y1),pii(x2,y2));
        if((!x1&&!y1)||(!x2&&!y2)) zz=true;
    }

    ans=zz?n-1:n;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans-=merge(i,j);
    
    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}