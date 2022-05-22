#include <iostream>

using namespace std;

int N, K, ans, arr[100000];

void Input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void Solution()
{
    for (int i = 1; i < N; i++)
        arr[i] = arr[i] + arr[i - 1];
    ans = arr[K - 1];
    for (int i = K; i < N; i++)
        ans = max(ans, arr[i] - arr[i - K]);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}