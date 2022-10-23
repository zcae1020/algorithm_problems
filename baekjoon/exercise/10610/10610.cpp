#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string N,ans;
int sum, arr[10];

void Solution() {
    cin>>N;
    for(auto c:N){
        sum+=c-'0';
        arr[c-'0']++;
    }

    if(sum%3==0 && arr[0]){
        for(int i=9;i>=0;i--)
            while(arr[i]--)
                cout<<i;
    }
    else cout<<-1;
}

int main() {
    FASTIO
    Solution();
}