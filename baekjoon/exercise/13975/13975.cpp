#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxK = 1e6+10;

int T,K, psum[maxK];
unordered_map<ll, ll> dp;

void Solution() {
    cin>>T;
    while(T--){
        cin>>K;
        for(int i=0;i<K;i++)
            cin>>dp[(i<<20)+i];

        psum[0] = dp[0];
        for(int i=1;i<K;i++)
            psum[i] = psum[i-1]+dp[(i<<20)+i];
        
        for(int l = 1;l<=K;l++){
            for(int s = 0;s+l<K;s++){
                dp[(s<<20)+s+l] = 1e18;
                for(int m = s;m<s+l;m++){
                    dp[(s<<20)+s+l] = min(dp[(s<<20)+s+l], 
                        dp[(s<<20)+m]+dp[((m+1)<<20)+s+l]+(s==m?0:dp[(s<<20)+m])+(m+1==s+l?0:dp[((m+1)<<20)+s+l]));
                }
            }
        }

        cout<<dp[K-1]<<'\n';

        dp.clear();
    }
}

int main() {
    FASTIO
    Solution();
}