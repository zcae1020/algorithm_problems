#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 100;

int n,arr[maxn], sarr[maxn], ans;

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sarr[0] = 0;
    for(int i=1;i<=n;i++){
        sarr[i] = sarr[i-1]+arr[i];
        if(!sarr[i]) break;
        ans++;
    }

    sarr[n] = 0;
    for(int i=n-1;i>=0;i--){
        sarr[i] = sarr[i+1]+arr[i];
        if(!sarr[i]) break;
        ans++;
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}