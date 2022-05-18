#include <iostream>

using namespace std;

int N, ans, coin[6] = {500, 100, 50, 10, 5, 1};

int main()
{
    cin >> N;
    N = 1000 - N;
    for (int i = 0; i < 6; i++)
    {
        ans += N / coin[i];
        N -= coin[i] * (N / coin[i]);
    }
    cout << ans;
}