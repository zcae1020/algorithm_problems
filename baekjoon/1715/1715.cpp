#include <iostream>
#include <queue>

using namespace std;

int n, ans;
priority_queue<int> pq;

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(-a);
    }
}

void Solution()
{
    int a, b;
    while (pq.size() > 1)
    {
        a = pq.top(), pq.pop();
        b = pq.top(), pq.pop();
        pq.push(a + b);
        ans += (-a - b);
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