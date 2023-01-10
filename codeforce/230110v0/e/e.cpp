#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second
 
using namespace std;
 
const int maxn = 3e5;
 
int t,n, arr[maxn];
bool dp[maxn];
 
void Solution() {
    cin>>t;
    while(t--) {
        dp[0] = true;
 
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
        }
 
        for(int i=1;i<=n;i++) {
            if(dp[i-1]) {
                dp[i + arr[i]] = true;
            } 
            if(dp[i-arr[i]-1]){
                dp[i] = true;
            }
        }

        cout<<(dp[n]? "YES":"NO")<<'\n';
    }
}
 
int main() {
    FASTIO
    Solution();
}