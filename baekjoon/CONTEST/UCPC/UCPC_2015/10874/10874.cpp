#include <iostream>

using namespace std;

int n, arr[10];
int ans[10] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

void Input()
{
    cin >> n;
}

bool isEqual()
{
    for (int i = 0; i < 10; i++)
        if (ans[i] != arr[i])
            return false;
    return true;
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
            cin >> arr[j];
        if (isEqual())
            cout << i << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}