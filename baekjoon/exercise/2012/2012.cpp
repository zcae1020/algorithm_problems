#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, expect[500000];
long long ans;

void Input()
{
    cin >> N;
    for(int i=0;i<N;i++) cin>>expect[i];
}

void Solution()
{
    sort(expect, expect +N);
    for(int i=0;i<N;i++)
        ans+=abs(expect[i]-i-1);

    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}