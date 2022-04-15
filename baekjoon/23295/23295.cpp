#include <iostream>
#define MAX 100005

using namespace std;

int N, T, K, time[MAX], ans;

void Input()
{
    scanf("%d %d", &N, &T);
    while (N--)
    {
        scanf("%d", &K);
        while (K--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            time[a]++;
            time[b]--;
        }
    }

    for (int i = 1; i < MAX; i++)
        time[i] += time[i - 1];
}

void Solution()
{
    long long win = 0, mx = 0;
    for (int i = 0; i < T; i++)
        win += time[i];
    mx = win;
    for (int i = T; i < MAX; i++)
    {
        win += time[i];
        win -= time[i - T];
        if (win > mx)
        {
            mx = win;
            ans = i - T + 1;
        }
    }
    printf("%d %d", ans, ans + T);
}

int main()
{
    Input();
    Solution();
}