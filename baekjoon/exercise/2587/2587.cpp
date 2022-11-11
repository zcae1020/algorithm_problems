#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int arr[5], sum;

void Solution()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 5);
    cout << sum / 5 << '\n'
         << arr[2];
}

int main()
{
    FASTIO
    Solution();
}