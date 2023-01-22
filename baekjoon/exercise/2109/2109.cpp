#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e4 + 10;

int n, ans;
vector<pii> arr;
bool visited[maxn];

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        arr.push_back({-a,b});
    }

    sort(arr.begin(), arr.end());

    for(auto a: arr) {
        int i = a.sd;
        for(;visited[i]&&i>0;i--);

        if(i) {
            visited[i] = 1;
            ans-=a.fs;
        }
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}