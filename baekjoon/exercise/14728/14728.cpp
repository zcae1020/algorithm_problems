#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 101;
const int maxt = 1e4+1;

int n,t;
pii arr[maxn];
int dp[maxn][maxt];

void Solution() {
    cin>>n>>t;
    for(int i=1;i<=n;i++) {
        cin>>arr[i].fs>>arr[i].sd;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=t;j++) {
            if(j<arr[i].fs) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else {
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-arr[i].fs] + arr[i].sd);
            }
        }
    }

    cout<<dp[n][t];
}

int main() {
    FASTIO
    Solution();
}