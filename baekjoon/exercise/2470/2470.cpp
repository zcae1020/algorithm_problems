#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, mn = INT_MAX, ansl, ansr;
vector<int> arr;

void Input()
{
    cin >> n;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
}

void Solution()
{
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1, cur;

    while (l < r)
    {
        cur = arr[l] + arr[r];
        if (mn > abs(cur))
        {
            mn = abs(cur);
            ansl = arr[l], ansr = arr[r];
        }
        if (cur == 0)
            break;
        else if (cur < 0)
            l++;
        else
            r--;
    }

    cout << ansl << ' ' << ansr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}