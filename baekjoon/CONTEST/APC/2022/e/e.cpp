#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;


set<int> se;
int n;
int arr[100], sum;
int mx, mn = 1000, ans;
vector<int> height[101];
vector<int> mxx, mnn;

bool isComplete() {
    for(int i=0;i<n - 1;i++) {
        if(abs(arr[i]-arr[i+1]) > 1)
            return false;
    }
    return true;
}

void getMX() {
    int mx = 0;
    for(int i=0;i<n;i++) {
        if(mx< arr[i]) {
            mxx.clear();
            mx = arr[i];
        }
        if(mx == arr[i]) {
            mxx.push_back(i);
        }
    }
}

void getBlock(int n) {
    while(n) {
        getMX();
        for (auto a : mxx)
        {
            if (n == 0)
            {
                return;
            }
            arr[a]--;
            n--;
        }
    }
}

void dfs(int idx, int cnt) {
    int nn;
    if(arr[idx + 1] - arr[idx] > 1) {
        nn = (abs(arr[idx] - arr[idx + 1]) - 1) * cnt;
        ans += nn;
        getBlock(nn);
        dfs(idx+1, cnt + 1);
    }
    if(arr[idx - 1] - arr[idx] > 1) {
        nn = (abs(arr[idx] - arr[idx - 1]) - 1) * cnt;
        ans += nn;
        getBlock(nn);
        dfs(idx-1, cnt + 1);
    }
}

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];

        se.insert(arr[i]);

        height[arr[i]].push_back(i);
    }

    for(auto a: se) {
        for(auto b: height[a]){
            mn = 1000;
            if (arr[idx + 1] - arr[idx] > 1)
            {
                nn = (abs(arr[idx] - arr[idx + 1]) - 1) * cnt;
                ans += nn;
                getBlock(nn);
                dfs(idx + 1, cnt + 1);
            }
            if (arr[idx - 1] - arr[idx] > 1)
            {
                nn = (abs(arr[idx] - arr[idx - 1]) - 1) * cnt;
                ans += nn;
                getBlock(nn);
                dfs(idx - 1, cnt + 1);
            }
            mn = min()
        }
    }

    cout<<ans;
}

int main() {
    FASTIO
    Solution();
}