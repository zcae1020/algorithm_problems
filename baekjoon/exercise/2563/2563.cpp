#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n,sum;
bool dowhage[100][100];

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=a;j<a+10;j++){
            for(int k=b;k<b+10;k++){
                dowhage[j][k]=1;
            }
        }
    }

    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            sum+=dowhage[i][j];

    cout<<sum;
}

int main() {
    FASTIO
    Solution();
}

