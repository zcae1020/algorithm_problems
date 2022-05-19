#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, sgpd[4], ans;
string grade;
vector<int> g;
int dp[36];

int gradeToInt(const char c)
{
    switch (c)
    {
    case 'B':
        return 0;
    case 'S':
        return 1;
    case 'G':
        return 2;
    case 'P':
        return 3;
    case 'D':
        return 4;
    }
}

void Input()
{
    cin >> N;
    for (int i = 0; i < 4; i++)
        cin >> sgpd[i];
    cin >> grade;

    for (auto c : grade)
        g.push_back(gradeToInt(c));
}

void Solution()
{
    int range[5][2] = {
        {0, sgpd[0] - 1},
        {sgpd[0], sgpd[1] - 1},
        {sgpd[1], sgpd[2] - 1},
        {sgpd[2], sgpd[3] - 1},
        {sgpd[3], sgpd[3] * 2},
    };

    dp[0] = g[0] == 4 ? sgpd[3] : range[g[0]][1];

    for (int i = 1; i < N; i++)
    {
        if (g[i] == 4)
        {
            dp[i] = range[g[i]][0];
            continue;
        }

        int cost = dp[i - 1] + dp[i];

        if (cost > range[g[i]][1])
        { // 최댓값보다 클때
            dp[i] = 0;
            dp[i - 1] = range[g[i]][1];
        }
        else
        { // 최댓값보다 작을때
            dp[i] = range[g[i]][1] - dp[i - 1];
        }
    }

    for (int i = 0; i < N; i++)
        ans += dp[i];

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}