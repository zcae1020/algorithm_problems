#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

long long ti,q,d,k;
string str;

void Solution() {
    cin>>ti;
    while(ti--) {
        cin>>q;
        int smx = 0, tmx = 0;
        long long ssize = 0, tsize = 0;
        while(q--) {
            cin>>d>>k>>str;
            int mx = 0;
            for(auto c: str) {
                mx = max(mx, c-'a');
            }

            if(d == 1) {
                smx = max(mx, smx);
                ssize += str.size()*k;
            }
            else {
                tmx = max(mx, tmx);
                tsize += str.size()*k;
            }

            if(tmx > 0) {
                cout<<"YES";
            }
            else { // t다 a
                if(smx > 0) {
                    cout<<"NO";
                }
                else { //둘다 a
                    cout<<(ssize<tsize?"YES":"NO");
                }
            }
             
            cout<<'\n';
        }
    }
}

int main() {
    FASTIO
    Solution();
}