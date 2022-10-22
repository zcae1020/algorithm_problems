#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M;

void Solution()
{
    cin >> N >> M;
    cout << min(N * (M - 1) + N - 1, (N - 1) * M + M - 1);
}

int main()
{
    FASTIO
    Solution();
}