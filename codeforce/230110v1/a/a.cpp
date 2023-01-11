#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t;
string s;

void Solution() {
    cin>>t;
    while(t--) {
        cin>>s;

        bool flag = false;
        for(int i=1;i<s.size()-1;i++) {
            if(s[i]=='a') {
                flag = true;
                break;
            }
        }

        if(flag) {
            int idx;
            cout<<s[0];
            for(int i=1;i<s.size();i++) {
                if(s[i] =='a') {
                    cout<<" a ";
                    idx = i;
                    break;
                }
                cout<<s[i];
            }

            for(int i=idx+1;i<s.size();i++) {
                cout<<s[i];
            }
        }
        else {
            cout<<s[0]<<' ';
            for(int i=1;i<s.size()-1;i++) {
                cout<<s[i];
            }
            cout<<' '<<s[s.size()-1];
        }
        cout<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}