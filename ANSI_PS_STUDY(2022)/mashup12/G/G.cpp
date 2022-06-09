#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

void Solution()
{
    int n, m, ans = 0;
    vector<vector<int>> v;

    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> needSwap;

    for(int i=0;i<n;i++){
        vector<int> tv(v[i]);
        sort(tv.begin(), tv.end());
        for(int j=0;j<m;j++)
            if(tv[j]!=v[i][j]) needSwap.push_back(j);
        if(needSwap.size()) break;
    }

    if(needSwap.size()==0) ans=-1;
    else if(needSwap.size()>2) ans=1;
    else{
        for(int i=0;i<n;i++){
            swap(v[i][needSwap[0]], v[i][needSwap[1]]);
            for(int j=0;j<m-1;j++){
                if(v[i][j]>v[i][j+1]){
                    ans=1;
                    break;
                }
            }
            if(ans)
                break;
        }
    }

    if(ans==-1) cout<<"1 1\n";
    else if(ans==1) cout<<"-1\n";
    else cout<<needSwap[0]+1<<' '<<needSwap[1]+1<<'\n';
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}