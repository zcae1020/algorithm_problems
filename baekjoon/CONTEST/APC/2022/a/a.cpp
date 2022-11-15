#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;



struct tear{
    int t;
    int level;
} ;

bool compare(struct tear t1, struct tear t2) {
    if(t1.t == t2.t) {
        return t1.level > t2.level;
    }
    return t1.t < t2.t;
}

struct tear T[1000], origin[1000];
char input[1000];

void Solution() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>input;
        //T[i].t = input[0];
        switch(input[0]) {
            case 'B':
                T[i].t = 0;
                break;
            case 'S':
                T[i].t = 1;
                break;
            case 'G':
                T[i].t = 2;
                break;
            case 'P':
                T[i].t = 3;
                break;
            case 'D':
                T[i].t = 4;
                break;
        }

        T[i].level = atoi(input + 1);
        origin[i].t = T[i].t;
        origin[i].level = T[i].level;
        //cout<<T[i].t<<'\n'<<T[i].level;
    }

    sort(T, T+n, compare);

    int flag = 0, i1 = -1, i2 = -1;
    for(int i=0;i<n;i++) {
        if(T[i].t != origin[i].t || T[i].level != origin[i].level) {
            flag = 1;
            if(i1==-1)
                i1 = i;
            else
                i2 = i;
        }
    }

    if(flag) {
        cout<<"KO\n";
        char a;
        switch(T[i1].t) {
            case 0:
                a = 'B';
                break;
            case 1:
                a = 'S';
                break;
            case 2:
                a = 'G';
                break;
            case 3:
                a = 'P';
                break;
            case 4:
                a = 'D';
                break;
        }
        cout<<a<<T[i1].level<<' ';
        switch(T[i2].t) {
            case 0:
                a = 'B';
                break;
            case 1:
                a = 'S';
                break;
            case 2:
                a = 'G';
                break;
            case 3:
                a = 'P';
                break;
            case 4:
                a = 'D';
                break;
        }
        cout<<a<<T[i2].level<<' ';
    }
    else {
        cout<<"OK\n";
    }
}

int main() {
    FASTIO
    Solution();
}