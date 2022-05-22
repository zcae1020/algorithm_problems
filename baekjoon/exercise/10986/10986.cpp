#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
long long arr[1000000], cnt[1000], ans;
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i] = (arr[i] + arr[i - 1]) % M;
        cnt[arr[i]]++;
        
        if (arr[i] == 0)
            ans++;
    }
}

void Solution()
{

    for (int i = 0; i < M; i++)
        ans += (cnt[i] * (cnt[i] - 1)) / 2;

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}