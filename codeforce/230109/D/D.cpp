#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int gcd(int a, int b) { // a > b 일때
  if(b == 0) return a;	// gcd를 찾았다면 그 몫을 return
  else return gcd(b, a % b);
}

int t,n,ans;
map<int,int> m;
bool coprime[1001][1001];

void Solution() {
    coprime[1][1] = true;
    for(int i=1;i<=1000;i++) {
        for(int j=i+1;j<=1000;j++) {
            if(gcd(i,j)==1) {
                coprime[i][j] = true;
            }
        }
    }

    cin>>t;
    while(t--) {
        ans = 0;
        m.clear();
        cin>>n;
        int a;
        for(int i=1;i<=n;i++) {
            cin>>a;
            m[a] = i;
        }

        for(auto b: m) {
            for(auto c: m) {
                int mx = max(b.fs, c.fs);
                int mn = min(b.fs, c.fs);
                if(coprime[mn][mx]) {
                    ans = max(ans,b.sd+c.sd);
                }
            }
        }

        cout<<(ans?ans:-1)<<'\n';
    }
    
}

int main() {
    FASTIO
    Solution();
}
