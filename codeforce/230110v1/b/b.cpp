
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second
 
using namespace std;
 
int t,tc,n,k;

vector<vector<int>> v;
map<int, int> cnt;

const int maxn =2e5+10;
 
void Solution() {
    cin>>t;
    while(t--) {
        bool ans = false;
        v.clear();
        cnt.clear();
 
        cin>>tc;
        for(int i=0;i<tc;i++) {
            vector<int> tmp;

            bool flag = true;
 
            cin>>n;
            for(int j=0;j<n;j++) {
                cin>>k;
                tmp.push_back(k);

                if(!cnt[k]) {
                    flag = false;
                }

                cnt[k]++;
            }
 
            v.push_back(tmp);

            if(flag) {
                ans = true;
            }
        }

        if(ans) {
            cout<<"YES\n";
            continue;
        }
 
        for(int i=0;i<tc;i++) {
            bool flag = true;
            for(auto a: v[i]){
                if(cnt[a] < 2) {
                    flag = false;
                    break;
                }
            }
 
            if(flag) {
                ans = true;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<'\n';
    }
}
 
int main() {
    FASTIO
    Solution();
}