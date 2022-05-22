#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int N, M, K, ans;
int edge[310][310];
int dp[310][310]; // [도착][도시갯수]

void Input()
{
    cin >> N >> M >> K;
    int a, b, c;
    for (int i = 0; i < K; i++)
    {
        cin >> a >> b >> c;
        if (a < b)
            edge[a][b] = max(edge[a][b], c);
    }
}

void Solution()
{
    dp[1][1] = 0;
    for (int i = 2; i <= N; i++)
    { //도착
        dp[i][2] = edge[1][i];
        for (int j = 2; j < i; j++)
        { // 시작
            if (edge[j][i])
            {
                for (int k = 2; k < M; k++)
                {
                    if (dp[j][k] && dp[i][k + 1] < dp[j][k] + edge[j][i])
                        dp[i][k + 1] = dp[j][k] + edge[j][i];
                }
            }
        }
    }

    for (int k = 2; k <= M; k++)
        ans = max(ans, dp[N][k]);

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}