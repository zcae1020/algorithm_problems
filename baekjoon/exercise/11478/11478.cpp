#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long

using namespace std;

string str;
set<string> s;

void Solution() {
    cin>>str;
    for(int l = 1;l<=str.size();l++){
        for(int st = 0;st+l<=str.size();st++){
            s.insert(str.substr(st,l));
        }
    }

    cout<<s.size();
}

int main() {
    FASTIO
    Solution();
}