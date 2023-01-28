#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxv = 1e4+1;
int t,n,m;
ll dp[maxv];
vector<int> val;

void Solution() {
    cin>>t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        val.clear();
        dp[0] = 1;

        cin>>n;
        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            val.push_back(a);
        }
        cin>>m;

        for(auto v:val) {
            for(int i=v;i<=m;i++) {
                dp[i] += dp[i-v];
            }
        }

        cout<<dp[m]<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}