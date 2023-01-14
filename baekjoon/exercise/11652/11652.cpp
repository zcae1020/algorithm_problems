#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n,mx;
map<string, int> m;
vector<string> ans;
string s;

bool cmp(string a, string b) {
    if(a[0]=='-'&&b[0]!='-') {
        return true;
    }else if(a[0]!='-'&&b[0]=='-') {
        return false;
    }else if(a[0]=='-'&&b[0]=='-') {
        if(a.size()==b.size()) {
            return a>b;
        }
        return a.size()>b.size();
    } else {
        if(a.size()==b.size()) {
            return a<b;
        }
        return a.size()<b.size();
    }
}

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        if(s[0])
        m[s]++;
    }

    for(auto p:m) {
        if(p.sd > mx) {
            mx = p.sd;
            ans.clear();
            ans.push_back(p.fs);
        }
        else if(p.sd==mx) {
            ans.push_back(p.fs);
        }
    }

    sort(ans.begin(), ans.end(), cmp);

    cout<<ans.front();
}

int main() {
    FASTIO
    Solution();
}