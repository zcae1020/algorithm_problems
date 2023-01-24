#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[1000];
queue<pii> q;
bool visited[100000];

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    q.push({0,0});
    visited[0] = true;
    while(!q.empty()) {
        int cur = q.front().fs;
        int cnt = q.front().sd;
        q.pop();

        if(cur >= n-1) {
            cout<<cnt;
            return;
        }

        for(int next=cur+1;next<=cur+arr[cur];next++) {
            if(!visited[next]) {
                q.push({next, cnt+1});
                visited[next] =true;;
            }
        }
    }

    cout<<-1;
    return;
}

int main() {
    FASTIO
    Solution();
}