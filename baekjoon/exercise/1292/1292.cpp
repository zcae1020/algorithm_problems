#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int A, B, arr[1001], idx = 1;

void Solution()
{
    cin >> A >> B;
    for (int i = 1; idx <= 1000; i++)
    {
        for (int j = 0; j < i && idx <= 1000; j++)
        {
            arr[idx] = arr[idx - 1] + i;
            idx++;
        }
    }
    cout << arr[B] - arr[A - 1];
}

int main()
{
    FASTIO
    Solution();
}