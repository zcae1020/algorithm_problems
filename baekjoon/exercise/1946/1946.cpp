#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t,n,a,b;

void getAns() {
    int ans = 0;
    int mn = 1e7;
    vector<pii> v;
    cin>>n;
    
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for(auto p: v) {
        if(p.second < mn) {
            ans++;
            mn = p.second;
        }
    }

    cout<<ans<<'\n';
}

void Solution() {
    cin>>t;
    while(t--) {
        getAns();
    }
}

int main() {
    FASTIO
    Solution();
}