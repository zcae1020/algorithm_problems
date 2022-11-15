#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

stack<int> s;
int n;
int ans[1000000];
int idx[1000001];
int length;

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(length + 1 < x) {
            cout<<-1;
            return;
        }
        length = x;
        idx[x] = i;
        
        if(x-1==0)
            continue;
        ans[idx[x-1]]++;
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}