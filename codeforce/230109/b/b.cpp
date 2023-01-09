#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t,n,a;
bool flag;
map<int, bool> m;

void Solution() {
    cin>>t;
    while(t--) {
        flag = false;
        m.clear();
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>a;
            if(m[a]) {
                flag = true;
            }
            m[a] = true;
        }

        cout<<(flag?"NO":"YES")<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}
