#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N,K,C,origin[10], arr[10];
ll ans = 1e12;

bool canCook(ll t) {
    ll cnt = 0;
    for(int i=0;i<N;i++) {
        cnt+=t/arr[i];
    }

    return cnt >= K;
}

void getAns() {
    ll l = 1, r = 1e12, mid;
    while(l<=r) {
        mid = (l+r)/2;
        if(canCook(mid)) {
            ans = min(ans, mid);
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
}

void reduce(int idx, int remain) {
    if(idx == N || remain == 0) {
        getAns();
        return;
    }

    if(idx == N-1) {
        arr[idx] = origin[idx] - remain < 1 ? 1: origin[idx] - remain;
        reduce(idx+1, 0);
        arr[idx] = origin[idx];
        return;
    }

    for(int i=0;i<=remain&&origin[idx] - i>=1;i++) {
        arr[idx] = origin[idx] - i < 1 ? 1: origin[idx] - i;
        reduce(idx+1, remain - i);
        arr[idx] = origin[idx];
    }
}

void Solution() {
    cin>>N>>K>>C;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
        origin[i] = arr[i];
    }

    reduce(0, C);

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}