#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

struct node {
    int num = 0;
    node *left = 0;
    node *right = 0;
} head;

node *insert(node *cur, int n) {
    if (cur == NULL) {
        cur = new node();
        cur->num = n;
        cur->left = cur->right = NULL;
    } else if (cur->num > n) {
        cur->left = insert(cur->left, n);
    } else {
        cur->right = insert(cur->right, n);
    }
    return cur;
}

void printPost(node *cur) {
    if (cur->left != NULL) {
        printPost(cur->left);
    }
    if (cur->right != NULL) {
        printPost(cur->right);
    }
    cout << cur->num << '\n';
}

void Solution() {
    int n;
    node *head = NULL;

    while (cin >> n) {
        if (n == EOF)
            break;

        head = insert(head, n);
    }

    printPost(head);
}

int main() {
    FASTIO
    Solution();
}
