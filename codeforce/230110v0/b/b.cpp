#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t,n;

void Solution() {
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==3) {
            cout<<-1<<'\n';
            continue;
        }

        if(n%2) {
            for(int i=0,j=n;i<n/2;i++,j--) {
                cout<<j<<' ';
            }
            for(int i=0,j=1;i<=n/2;i++,j++){
                cout<<j<<' ';
            }
        }
        else {
            for(int i=n;i>0;i--) {
                cout<<i<<' ';
            }
        }
        cout<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}