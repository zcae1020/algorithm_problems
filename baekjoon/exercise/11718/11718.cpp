#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string s;

void Solution() {
    while (1) {
        getline(cin, s);
        if (cin.eof())
            break;
        cout << s << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}
