#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;
string s[8];
bool flag, f1;

void Solution() {
    cin>>n;
    while(n--) {
        for(int i=0;i<8;i++) {
            cin>>s[i];
        }

        f1 = false;

        for(int i=0;i<8;i++) {
            flag = true;
            char color = s[i][0];
            if(color != 'R') {
                continue;
            }
            for(int j=0;j<8;j++) {
                if(color != s[i][j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                f1 = true;
                cout<<"R\n";
                break;
            }
        }

        if(!f1) {
            cout<<"B\n";
        }
    }
}

int main() {
    FASTIO
    Solution();
}