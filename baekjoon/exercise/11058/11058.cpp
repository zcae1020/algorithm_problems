#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;
ll dp[101];

void Solution() {
    cin>>n;
    for(int i=0;i<=n;i++) {
        dp[i] = i;
    }

    for(int i=0;i<=n;i++) {
        for(int j=0;j<i-3;j++) {
            for(int k=0;k<i-j;k++) {
                dp[i] = max(dp[i], (dp[j]+k)*(i-1-j-k));
            }
        }
    }

    cout<<dp[n];
}

int main() {
    FASTIO
    Solution();
}