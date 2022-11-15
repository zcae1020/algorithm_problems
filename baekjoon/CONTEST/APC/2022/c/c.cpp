#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n,m;
map<pair<int, pair<char, char>>, vector<string>> um;

bool isupper(char a) {
    return 'A'<=a&&a<='Z';
}

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        string input;
        cin>>input;
        um[{input.length(), {input.front(), input.back()}}].push_back(input);
    }

    cin>>m;
    for(int i=0;i<m;i++) {
        string s;
        cin>>s;
        int acnt[26] = {0}, Acnt[26] = {0};
        for(int i=1;i<s.length()-1;i++) {
            if(isupper(s[i])) {
                Acnt[s[i]-'A']++;
            }
            else{
                acnt[s[i]-'a']++;
            }
        }
        for(auto str:um[{s.length(),{s.front(), s.back()}}]) {
            int aacnt[26] = {0}, AAcnt[26] = {0};
            for(int i=1;i<str.length()-1;i++) {
                if(isupper(str[i])) {
                    AAcnt[str[i]-'A']++;
                }
                else{
                    aacnt[str[i]-'a']++;
                }
            }

            int flag = 0;
            for(int i=0;i<26;i++) {
                if(acnt[i] != aacnt[i]){
                    flag = 1;
                    break;
                }
                if(Acnt[i] != AAcnt[i]){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                cout<<str<<' ';
                break;
            }
        }
    }
}

int main() {
    FASTIO
    Solution();
}