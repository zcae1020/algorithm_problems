#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int N, M, K;
vector<double> v[100];

void Input()
{
    scanf("%d %d %d", &N, &M, &K);
    int a;
    double b;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d %lf", &a, &b);
            v[a - 1].push_back(b);
        }
    }
}

void Solution()
{
    vector<double> score;
    for (int i = 0; i < N; i++)
        sort(v[i].begin(), v[i].end(), greater<double>());

    for (int i = 0; i < N; i++)
        score.push_back(v[i][0]);

    sort(score.begin(), score.end(), greater<double>());

    double ans = 0.0;
    for (int i = 0; i < K; i++)
        ans += score[i];

    printf("%.1lf", ans);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}