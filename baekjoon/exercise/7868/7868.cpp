#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define x first
#define y second

using namespace std;

const ull maxn = 1e18;

ull p[3], input,ans = 1;
set<ull> s;

void Solution() {
    for(int i=0;i<3;i++) cin>>p[i];
    cin>>input;

    sort(p, p+3);

    for(int i=0;i<3;i++){
        for(ull cur = p[i];cur<=1e18&&cur<p[0]*p[1]*p[2];cur*=p[i]){
            for(auto n:s){
                if(n*cur<=1e18&&n*cur<p[0]*p[1]*p[2])
                    s.insert(n*cur);
                else break;
            }
            s.insert(cur);
        }
    }

    if(input/s.size())
        for(int i=0;i<input/s.size();i++, ans*=(p[0]*p[1]*p[2]));

    int rest = input%s.size();
    if(rest){
        for(auto n:s){
            rest--;
            if(!rest) {
                ans*=n;
                break;
            }
        }
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}