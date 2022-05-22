#include <iostream>
#include <cmath>

using namespace std;

int n, os1,os2, u, use[20], ans=1e9;

void Input() {
    cin>>n>>os1>>os2>>u;
    for(int i=0;i<u;i++) cin>>use[i];
}

void dfs(int idx, int an, int o1, int o2){
    if(idx==u){
        ans = min(ans, an);
        return;
    }
    dfs(idx+1, an+abs(use[idx]-o1), use[idx], o2);
    dfs(idx+1, an+abs(use[idx]-o2), o1, use[idx]);
}

void Solution() {
    dfs(0, 0, os1,os2);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}

