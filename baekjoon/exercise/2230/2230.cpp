#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e6+10;

int n, m, arr[maxn], ans = 2e9;

void Solution() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    sort(arr, arr+n);

    for(int i=0;i<n;i++) {
        int idx = lower_bound(arr, arr+n, arr[i]+m) - arr;
        if(idx != n) {
            ans = min(ans, arr[idx] - arr[i]);
        }
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}