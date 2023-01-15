#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string s1, s2;
int ans = 100;

void Solution() {
    cin>>s1>>s2;

    for(int i=0;i+s1.size()<=s2.size();i++) {
        string sub = s2.substr(i, s1.size());
        int cnt = 0;
        for(int j=0;j<sub.size();j++) {
            if(sub[j]!=s1[j]) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}