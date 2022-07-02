#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, sum, arr[1000];

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    sum = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sum)
            break;
        else
            sum += arr[i];
    }

    cout << sum;
}

int main()
{
    FASTIO
    Solution();
}