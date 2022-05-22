#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dp[1001], n, k, ans, b[1000], w[1000], c[1000], knapsack[1000][15001];

void fillDP()
{
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = cur; i > 0; i--)
        {
            int next = cur + cur / i;
            if (next > 1000)
                break;
            if (dp[next] == 0)
            {
                dp[next] = dp[cur] + 1;
                q.push(next);
            }
        }
    }
}

void Input()
{
    cin >> n >> k;

    k = k >= 15000 ? 15000 : k;
    ans = 0;
    memset(knapsack, 0, sizeof(knapsack));

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        w[i] = dp[a];
    }

    for (int i = 0; i < n; i++)
        cin >> c[i];
}

void Solution()
{
    for (int i = w[0]; i <= k; i++)
        knapsack[0][i] = c[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < w[i]; j++)
            knapsack[i][j] = knapsack[i - 1][j];
        for (int j = w[i]; j <= k; j++)
            knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i - 1][j - w[i]] + c[i]);
    }

    cout << knapsack[n - 1][k] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    dp[1] = 0;
    fillDP();

    int t;
    cin >> t;
    while (t--)
    {
        Input();
        Solution();
    }
}