#include <iostream>

using namespace std;

int n, m, sum[100000];

void Input()
{
    cin >> n >> m;
    int a;
    cin >> a;
    sum[0] = a;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        sum[i] = a + sum[i - 1];
    }
}

void Solution()
{
    int s, e;
    while (m--)
    {
        cin >> s >> e;
        if (s == 1)
            cout << sum[e - 1];
        else
            cout << sum[e - 1] - sum[s - 2];
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}