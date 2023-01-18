#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const ll maxn = 1e12; // 오로지 12여야만함
int n;
ll fact = 1;

void Solution() {
    cin>>n;
    
    for(int i=1;i<=n;i++) {
        fact*=i;
        while(fact%10 == 0) {
            fact/=10;
        }
        fact%=maxn;
    }

    string ans = to_string(fact);
    for(int i=ans.size()-5;i<ans.size();i++) {
        cout<<ans[i];
    }
}

int main() {
    FASTIO
    Solution();
}