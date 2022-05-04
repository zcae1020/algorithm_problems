#include <iostream>
#include <cstring>
#define MAX 1000000000

using namespace std;

int V,E, ans = MAX;
int D[400][400];

void Input() {
    cin>>V>>E;

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            D[i][j]=MAX;

    int a,b,c;
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        a--,b--;
        D[a][b]=c;
    }
}

void Solution() {
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);

    for(int i=0;i<V;i++) ans=min(ans, D[i][i]);

    if(ans==MAX) cout<<-1;
    else cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}

