#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t,n;
vector<int> prime;

void getPrime(int sum) {
    prime.clear();

    for(int i=1;i*i<=sum;i++) {
        if(sum%i==0) {
            prime.push_back(i);
            prime.push_back(sum/i);
        }
    }
}

void Solution() {
    cin>>t;
    while(t--) {
        int sum = 0, ans = 1e5;
        vector<int> v;
        cin>>n;
        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            v.push_back(a);
            sum+=a;
        }

        getPrime(sum);

        for(auto p:prime) {
            int cur = 0;
            int idx = -1;
            int thickness = 0;
            bool f = true;
            for(int i=0;i<n;i++) {
                cur+=v[i];

                if(cur == p) {
                    cur = 0;
                    thickness = max(thickness, i-idx);
                    idx = i;
                }
                if(cur > p) {
                    f=false;
                    break;
                }
            }
            if(f) {
                ans = min(ans, thickness);
            }
        }

        cout<<ans<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}