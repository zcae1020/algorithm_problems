#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1001;

int t,n,m, par[maxn];

int find(int u) {
    return u==par[u] ? u:par[u] = find(par[u]);
}

void merge(int u, int w) {
    u = find(u), w = find(w);

    par[u] = w;
}

void Solution() {
    cin>>t;
    while(t--) {
        int ans = 0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) {
            par[i] = i;
        }

        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            if(find(a) != find(b)) {
                merge(a,b);
                ans++;
            }
        }

        cout<<ans<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}