#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

string s, e;
stack<pair<char, int>> st;

void Solution()
{
    cin >> s >> e;

    for (auto a : s)
    {
        if (st.empty())
        {
            if (e[0] == a)
                st.push({a, 1});
            else
                st.push({a, 0});
        }
        else
        {
            int idx = st.top().y;
            if (e[idx] == a)
                st.push({a, idx + 1});
            else
            {
                if (e[0] == a)
                    st.push({a, 1});
                else
                    st.push({a, 0});
            }
        }

        if (st.top().y == e.size())
            for (int i = 0; i < e.size(); i++)
                st.pop();
    }

    if (st.empty())
        cout << "FRULA";
    else
    {
        string t;
        while (st.size())
        {
            t.push_back(st.top().x);
            st.pop();
        }
        reverse(t.begin(), t.end());
        cout << t;
    }
}

int main()
{
    FASTIO
    Solution();
}