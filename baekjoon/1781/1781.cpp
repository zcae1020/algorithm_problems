#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;

int N, ans;
pii arr[200000];

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
}

void Solution()
{
    sort(arr, arr + N);
    priority_queue<int> pq;
    for (int i = N, j = N - 1; i > 0; i--)
    {
        while (j >= 0 && arr[j].first >= i)
            pq.push(arr[j--].second);
        if (pq.size())
        {
            ans += pq.top();
            pq.pop();
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