#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int T, N;
long long ans;
string str;
vector<int> sheep;
 
void Input()
{
    cin >> N >> str;
    sheep.clear();
    ans = 0;
}
 
void Solution()
{
    for (int i = 0; i < N; i++)
        if (str[i] == '*')
            sheep.push_back(i);
 
    if (sheep.empty())
    {
        cout << 0 << '\n';
        return;
    }
 
    int s = sheep[sheep.size() / 2] - sheep.size() / 2;
 
    for (int i = s; i < s + sheep.size(); i++)
        ans += abs(sheep[i - s] - i);
 
    cout << ans << '\n';
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