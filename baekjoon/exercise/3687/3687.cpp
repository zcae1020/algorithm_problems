#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

map<int, vector<int>> m;

int tc;

void getMx(int n) {
    if(n%2) {
        cout<<7;
        n-=3;
    }
    for(int i=1;i*2<=n;i++) {
        cout<<1;
    }
}

// void getMn(int n) {
//     vector<int> nums;
//     while(n>13) {
//         nums.push_back(m[7][0]);
//         n-=7;
//     }

//     if(n<=7) {
//         nums.push_back(m[n][0]);
//     }
//     else {
//         if(n==8) {
//             nums.push_back(m[6][0]);
//             nums.push_back(m[2][0]);
//         }
//         else if(n==9) {
//             nums.push_back(m[2][0]);
//             nums.push_back(m[7][0]);
//         }
//         else if(n==10) {
//             nums.push_back(m[5][0]);
//             nums.push_back(m[5][0]);
//         }
//         else if(n==12) {
//             nums.push_back(m[5][0]);
//             nums.push_back(m[7][0]);
//         }
//         else { //11, 13
//             nums.push_back(m[6][0]);
//             nums.push_back(m[n-6][0]);
//         }
//     }

//     sort(nums.begin(), nums.end());

//     if(nums.back() == 0) { // n == 6
//         cout<<6;
//     }
//     else {
//         if(nums.front() == 0) { // 0 포함
//             int idx = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();

//             cout<<nums[idx];

//             for(int i=0;i<nums.size();i++) {
//                 if(i==idx) {
//                     continue;
//                 }
//                 cout<<nums[i];
//             }
//         }
//         else {
//             for(auto num:nums) {
//                 cout<<num;
//             }
//         }
//     }
// }

void Solution() {
    int min_num[8] = { 0,0,1,7,4,2,0,8 };
    ll dp[101];
    
	memset(dp, 0x7f , sizeof(dp));
	dp[1] = 9; dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8;

	for (int i= 8; i<=100; i++) 
		for (int j = 2; j<=7; j++) 
			dp[i] = min(dp[i], dp[i-j]*10 + min_num[j]);

    cin>>tc;
    while(tc--) {
        int n;
        cin>>n;
        cout<<dp[n]<<' ';
        getMx(n);
        cout<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}