#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e5;
int n, arr[maxn], ans = INT_MAX;

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int l = 0, r = n-1;
    while(l<r) {
        int cur = arr[l] + arr[r];
        ans = abs(ans) > abs(cur)?cur: ans;
        
        if(cur > 0) {
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