#include <iostream>
#define MAX 1000000000

using namespace std;

int N, M, ans = MAX;
int jewelry[300000];

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> jewelry[i];
}

bool can(int m)
{
    int need = 0;
    for (int i = 0; i < M; i++)
    {
        need += (jewelry[i] / m);
        if (jewelry[i] % m)
            need++;
    }
    return need <= N ? true : false;
}

void Solution()
{
    int l = 1, r = MAX, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (can(m))
        {
            r = m - 1;
            ans = min(ans, m);
        }
        else
            l = m + 1;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}