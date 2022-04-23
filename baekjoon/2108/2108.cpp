#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, arr[500000], have[8001], sum;
vector<int> h;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        have[arr[i] + 4000]++;
        sum += arr[i];
    }

    int hmx = 0;
    for (int i = 0; i <= 8000; i++)
    {
        if (have[i] > hmx)
        {
            h.clear();
            h.push_back(i - 4000);
            hmx = have[i];
        }
        else if (have[i] == hmx)
            h.push_back(i - 4000);
    }

    sort(arr, arr + n);

    printf("%d\n", (int)(round((double)sum / n)));
    printf("%d\n", arr[(n - 1) / 2]);

    if (h.size() > 1)
        printf("%d", h[1]);
    else
        printf("%d", h[0]);
    printf("\n");

    printf("%d", arr[n - 1] - arr[0]);
}