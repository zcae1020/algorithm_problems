#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxm = 3e5;

int t,m, arr[maxm];

pair<pii,int> dq(int s, int e, int height) {
    int mid = (s+e)/2;

    if(s+1==e) {
        return {{arr[s], arr[s]}, 0};
    }

    pair<pii,int> l = dq(s,mid, height-1);
    pair<pii,int> r = dq(mid, e, height-1);

    int ans = l.sd+r.sd;
    pii pans;

    if(l.sd==-1||r.sd==-1) {
        return {{0,0},-1};
    }

    if(l.fs.sd+1!=r.fs.fs&&r.fs.sd+1!=l.fs.fs) {
        return {{0,0},-1};
    }

    if(r.fs.sd+1 == l.fs.fs) {
        pans = {r.fs.fs, l.fs.sd};
        ans++;
    }
    else {
        pans = {l.fs.fs, r.fs.sd};
    }

    return {pans, ans};
}

void Solution() {
    cin>>t;
    while(t--) {
        cin>>m;
        for(int i=0;i<m;i++) {
            cin>>arr[i];
        }

        int cnt = 0;
        int tmp = 1;
        while(tmp<m) {
            tmp*=2;
            cnt++;
        }

        cout<< dq(0,m, cnt).sd<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}