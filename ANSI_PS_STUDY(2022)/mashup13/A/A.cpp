#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn =10;

void Solution() {
    int n,k,arr[maxn];
    ll sum = 0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        arr[i]-=(n-i-1);  
    }

    for(int i=0;i<k;i++) {
        if(arr[i]<=0) break;
        sum-=arr[i];
    }

    cout<<sum<<'\n';
}

int main() {
    FASTIO
    int tc;
    cin>>tc;
    while(tc--)
        Solution();
}