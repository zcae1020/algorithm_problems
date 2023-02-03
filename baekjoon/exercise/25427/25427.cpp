#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll N, D, K, S, ans;
string str;

void Solution() {
    cin>>N>>str;

    for(int i=0;i<N;i++) {
        switch(str[i]) {
            case 'D':
                D++;
                break;
            case 'K':
                K+=D;
                break;
            case 'S':
                S+=K;
                break;
            case 'H':
                ans += S;
                break;
        }
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}