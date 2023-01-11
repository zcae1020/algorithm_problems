#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

llu t,n,x,ans;

vector<int> ten_to_tw(llu n) {
    vector<int> ret;
    llu a = ULONG_LONG_MAX; // 1000 0000 0000 0000 0000 0000 0000 0000(2) <약 21억>
    for (int i = 0; i < 32; i++) {
        ret.push_back((a & n) == a);
        a >>= 1;
    }

    return ret;
}

vector<int> ten_to_two(llu n) {
    vector<int> ret;
    if (n < 2) { // n==1 (이전 n이 2이거나 3)
        ret.push_back(n);
    }
    else {
        ret = ten_to_two(n / 2);
        ret.push_back(n%2);
    }

    return ret;
}

llu two_to_ten(vector<int> v) {
    llu ret = 0;
    llu cnt = 1;
    for(int i=v.size()-1;i>=0;i--) {
        ret+=v[i]*cnt;
        cnt*=2;
    }
    return ret;
}

void Solution() {
    cin>>t;
    while(t--) {
        cin>>n>>x;

        if(x>n) {
            cout<<-1<<'\n';
            continue;
        }
        if(x==n) {
            cout<<x<<'\n';
            continue;
        }

        ans = 0;
        vector<int> nt = ten_to_two(n);
        vector<int> xt = ten_to_two(x);
        vector<int> ansv;

        if(x==0) {
            ansv.push_back(1);
            for(int i=0;i<nt.size();i++) {
                ansv.push_back(0);
            }   
            cout<<two_to_ten(ansv)<<'\n';
            continue;
        }

        if(nt.size() != xt.size()) {
            cout<<-1<<'\n';
            continue;
        }
        
        for(int i=nt.size();i>=0;i--) {
            if(xt[i]==1 && nt[i]==0) {
               ans = -1;
               break; 
            }
        }

        if(ans == -1) {
            cout<<-1<<'\n';
            continue;
        }


        bool f = false;
        for(int i=0;i<nt.size()&&i<xt.size();i++) {
            if(nt[i]==1 && xt[i]==0) {
                if(f) {
                    ans=-1;
                    break;
                }
                
                f = true;
                for(int j=0;j<i-1;j++) {
                    ansv.push_back(nt[i]);
                }
                ansv.push_back(1);

                for(int j=i;j<nt.size();j++) {
                    ansv.push_back(0);
                }

                ans = two_to_ten(ansv);
            }
        }

        cout<<ans<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}
