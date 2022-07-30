#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

struct tree{
    tree* next[27];
} root;

int n, ans;
string s;
unordered_set<string> us[26];

void add(string x){
    tree cur = root;
    for(int i=0;i<x.size();i++)
        if(!cur.next[x[0]-'a'])
            cur.next[x[0]-'a'] = (tree*)malloc(sizeof(tree));
    cur.next[26] = (tree*)malloc(sizeof(tree));
}
fhdj
void dfs(int idx, int cnt){
    if(cnt==3){
        if(idx==s.size()) ans++;
        return;
    }

    tree cur = root;
    for(int i=idx;i<s.size();i++){
        
    }
}

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        us[x[0]-'a'].insert(x);
    }
    cin>>s;

}

int main() {
    FASTIO
    Solution();
}