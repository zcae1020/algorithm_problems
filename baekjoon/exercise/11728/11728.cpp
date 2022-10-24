#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int m = 2e6+10;
int N,M,arr[m];

void Solution() {
    cin>>N>>M;
    for(int i=0;i<N+M;i++)
        cin>>arr[i];
    
    sort(arr, arr+N+M);

    for(int i=0;i<N+M;i++)
        cout<<arr[i]<<' ';
}

int main() {
    FASTIO
    Solution();
}