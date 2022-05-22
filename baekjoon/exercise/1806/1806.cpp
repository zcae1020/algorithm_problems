#include <iostream>
#define MAX 1000000

using namespace std;

int N, S, arr[100000], ans = MAX;

void Input()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void Solution()
{
    int l, r, s;
    l = r = s = 0;
    while (r <= N)
    {
        if (s >= S)
        {
            ans = min(ans, r - l);
            s -= arr[l++];
        }
        else
            s += arr[r++];
    }
    if (ans == MAX)
        cout << 0;
    else
        cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}