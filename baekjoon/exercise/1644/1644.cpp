#include <iostream>
#include <vector>

using namespace std;

int N, arr[4000000], ans;
vector<int> prime;

void Input()
{
    cin >> N;
}

void getPrime()
{
    for (int i = 2; i <= N; i++)
    {
        if (arr[i])
            continue;
        prime.push_back(i);
        for (int j = i; j <= N; j += i)
            arr[j] = i;
    }
}

void Solution()
{
    if (N == 1)
    {
        cout << 0;
        return;
    }
    
    getPrime();

    int l, r, sum;
    l = r = sum = 0;
    while (r <= prime.size())
    {
        if (sum == N)
        {
            ans++;
            sum += prime[r++];
        }
        else if (sum < N)
            sum += prime[r++];
        else
            sum -= prime[l++];
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