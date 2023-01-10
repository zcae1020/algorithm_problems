#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t;
string s1, s2;

int comp() {
    if(s1 == s2) {
        return 0;
    }

    if(s1.back() != s2.back()) {
        switch(s1.back()) {
            case 'L':
                return 1; // s1이 큼
            case 'M':
                if(s2.back() == 'L') {
                    return -1;
                }
                return 1;
            case 'S':
                return -1;
        }
    }
    
    if(s1.back() == 'S') {
        return (s1.size() > s2.size() ? -1:1);
    }

    return (s1.size() < s2.size() ? -1:1);
}

void Solution() {
    cin>>t;
    while(t--) {
        cin>>s1>>s2;
        int c = comp();
        if(c < 0) {
            cout<<"<\n";
        }
        else if(!c) {
            cout<<"=\n";
        }
        else {
            cout<<">\n";
        }
    }
}

int main() {
    FASTIO
    Solution();
}