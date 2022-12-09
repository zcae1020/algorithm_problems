#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, sum, idx, cnt[101];

int percent[9] = {4,11,23,40,60,77,89,96,100};
int mx = 0;

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        cnt[x]++;
    }

    for(int i=100;i>=0;i--) {
        sum+=cnt[i];
        if(idx < 9 && percent[idx] <= sum) {
            printf("%d\n", sum - mx);
            mx = sum;
            idx++;
            while(idx < 9 && percent[idx] <= sum) {
                idx++;
                printf("0\n");
            }
        }
    }
}

int main() {
    FASTIO
    Solution();
}