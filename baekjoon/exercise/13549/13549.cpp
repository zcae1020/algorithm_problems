#include <iostream>
#include <queue>
#include <functional>
#define pii pair<int, int>
#define MAX 100000

using namespace std;

int N, K;
bool map[MAX + 1];

void Input()
{
    cin >> N >> K;
}

void Solution()
{
    priority_queue<pii, vector<pii>, greater<>> q;
    q.push({0, N});
    map[N] = 1;

    while (!q.empty())
    {
        int cnt = q.top().first, cur = q.top().second;
        q.pop();

        if (cur == K)
        {
            cout << cnt;
            break;
        }

        if (2 * cur <= MAX && !map[2 * cur])
        {
            q.push({cnt, 2 * cur});
            map[2 * cur] = 1;
        }
        if (cur - 1 >= 0 && !map[cur - 1])
        {
            q.push({cnt + 1, cur - 1});
            map[cur - 1] = 1;
        }
        if (cur + 1 <= MAX && !map[cur + 1])
        {
            q.push({cnt + 1, cur + 1});
            map[cur + 1] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}