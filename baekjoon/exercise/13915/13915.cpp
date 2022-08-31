#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;
set<string> s;

void Solution() {
    while(true){
        int n;
        unordered_set<string> s;
        string str;

        cin>>n;
        if(cin.eof()) return;

        for(int i=0;i<n;i++){
            cin>>str;
            sort(str.begin(), str.end());
            string sstr;

            sstr.push_back(str.front());
            for(auto c:str)
                if(sstr.back()!=c)
                    sstr.push_back(c);
            
            s.insert(sstr);
        }

        cout<<s.size()<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}