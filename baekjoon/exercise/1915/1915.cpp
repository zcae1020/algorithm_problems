#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n,m, parr[1001][1001], ans = 1;
bool hasOne;
string input[1001];

void getAns(int x, int y) {
    for(int i=x+ans, j=y+ans;i<=n&&j<=m;i++,j++) {
        if((i-x)*(i-x)==parr[i][j] + parr[x][y] - parr[i][y] - parr[x][j]) {
            ans = max(ans, i-x);
        }
        else {
            return;
        }
    }
}

void Solution() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>input[i];
        for(int j=0;j<m;j++) {
            if(input[i][j]=='1') {
                hasOne = true;
            }
        }
    }

    if(!hasOne) {
        cout<<0;
        return;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            parr[i][j] = input[i-1][j-1] - '0' + parr[i][j-1] + parr[i-1][j] - parr[i-1][j-1];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            getAns(i,j);
        }
    }

    cout<<ans*ans;
}

int main() {
    FASTIO
    Solution();
}