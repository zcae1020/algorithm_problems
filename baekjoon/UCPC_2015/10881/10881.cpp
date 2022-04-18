#include <iostream>

using namespace std;

int T, ans;
int arr[3][2];

void Input()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int minBox(int a, int b, int c)
{
    int sumBox1, sumBox2, ret = 1000000;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sumBox1 = arr[a][i] + arr[b][j];
            sumBox2 = max(arr[a][!i], arr[b][!j]);

            ret = min(ret, min(
            min((sumBox1 + arr[c][0]) * max(sumBox2, arr[c][1]),
               (sumBox1 + arr[c][1]) * max(sumBox2, arr[c][0])),
            min(max(sumBox1, arr[c][0]) * (sumBox2 + arr[c][1]),
               max(sumBox1, arr[c][1]) * (sumBox2 + arr[c][0]))));
        }
    }
    return ret;
}

void Solution()
{
    cout << min(minBox(0, 1, 2), min(minBox(1, 2, 0), minBox(0, 2, 1))) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        Input();
        Solution();
    }
}