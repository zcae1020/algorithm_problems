#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxN = 2001;

int N, M, arr[maxN];
bool dp[maxN][maxN];

void Solution()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i][i] = 1;
    }

    for (int i = 1; i < N; i++)
        dp[i][i + 1] = (arr[i] == arr[i + 1]);

    for (int l = 2; l < N; l++)
        for (int s = 1; s + l <= N; s++)
            dp[s][s + l] = (arr[s] == arr[s + l] && dp[s + 1][s + l - 1]);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}