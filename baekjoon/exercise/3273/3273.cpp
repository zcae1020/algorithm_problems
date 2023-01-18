#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e6;
int n, arr[maxn], x;
ll ans = 0;

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>x;

    sort(arr, arr+n);

    int l = 0, r = n-1;
    while(l<=r) {
        if(arr[l]+arr[r] == x) {
            ans++;
            l++;
        }
        else if(arr[l]+arr[r] > x) {
            r--;
        }
        else {
            l++;
        }
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}