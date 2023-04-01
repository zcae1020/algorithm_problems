#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string str[5];

void Solution() {
    for (int i = 0; i < 5; i++) {
        cin >> str[i];
    }

    for (int i = 1; i <= 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[j].length() >= i) {
                cout << str[j][i - 1];
            }
        }
    }
}

int main() {
    FASTIO
    Solution();
}