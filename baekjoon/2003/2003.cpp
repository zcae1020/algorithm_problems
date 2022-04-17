#include <iostream>

using namespace std;

int n, m, arr[10000], ans;

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solution()
{
    int l, r, sum;
    l = r = sum = 0;
    while (r <= n)
    {
        if (sum == m)
        {
            ans++;
            sum -= arr[l];
            l++;
        }
        else if (sum < m)
        {
            sum += arr[r];
            r++;
        }
        else
        {
            sum -= arr[l];
            l++;
        }
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