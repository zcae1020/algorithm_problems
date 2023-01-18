#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e5;
int n, arr[maxn], x, ans;

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>x;

    sort(arr, arr+n);

    int l = 0, r = n-1;
    while(l<r) {
        int sum = arr[l]+arr[r];
        if(sum == x) {
            ans++;
            l++;
        }
        else if(sum > x) {
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