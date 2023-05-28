#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;

map<char, char> m;

string before = "acijnot";
string after = "@[!;^07";

string input, ans;

void Solution() {
    for (int i = 0; i < 7; i++) {
        m[after[i]] = before[i];
    }

    cin >> n;
    while (n--) {
        cin >> input;

        ans.clear();
        int cnt = 0;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                ans.push_back(input[i]);
            } else {
                cnt++;
                if (input[i] == '\\') {
                    if (input[i + 1] == '\'') {
                        ans.push_back('v');
                        i++;
                    } else if (input[i + 1] == '\\' && input[i + 2] == '\'') {
                        ans.push_back('w');
                        i += 2;
                    } else {
                        cnt = 1e9;
                        break;
                    }
                } else {
                    if (!m[input[i]]) {
                        cnt = 1e9;
                        break;
                    } else {
                        ans.push_back(m[input[i]]);
                    }
                }
            }
        }

        if (cnt >= ans.size() - cnt) {
            cout << "I don't understand" << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}

int main() {
    FASTIO
    Solution();
}