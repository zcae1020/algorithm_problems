#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[10001];
bool ans;

priority_queue<int> pq;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; i--)
    {
        pq.push(arr[i]);

        if (pq.top() != arr[i])
        {
            sort(arr+i+1, arr+n);

            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    swap(arr[i], arr[j]);
                    break;
                }
            }

            for (int j = 0; j < n; j++)
                cout << arr[j] << ' ';

            return;
        }
    }

    cout << -1;
}

int main()
{
    FASTIO
    Solution();
}