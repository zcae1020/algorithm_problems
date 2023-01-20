#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 3e5 + 10;

int n,k;
int parr[maxn][21];
int len[maxn];

ll ans;

void Solution() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;

        len[i] = s.size();

        for(int j=2;j<=20;j++) {
            parr[i][j] = parr[i-1][j];
        }

        parr[i][s.size()]++;
    }

    for(int i=1;i<=n;i++) {
        int mx = i+k>n?n:i+k;
        ans += parr[mx][len[i]] - parr[i][len[i]];
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}