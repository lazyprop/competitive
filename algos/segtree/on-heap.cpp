// dynamic segtree implementation on the heap
// utterly useles and very slow. do not use.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    int tl, tr;
    ll sum;
    node *left, *right;
};

void build(int tl, int tr, int a[], node *v) {
    v->tl = tl;
    v->tr = tr;

    if (tl == tr) {
        v->sum = a[tl];
    } else {
        v->left = (node*) malloc(sizeof(node));
        v->right = (node*) malloc(sizeof(node));

        int tm = (tl + tr) / 2;
        build(tl, tm, a, v->left);
        build(tm+1, tr, a, v->right);

        v->sum = v->left->sum + v->right->sum;
    }
}

ll sum(int l, int r, node *v) {
    if (l > r) return 0;
    if (l == v->tl && r == v->tr) return v->sum;

    return sum(l, min(r, v->left->tr), v->left)
        + sum(max(l, v->right->tl), r, v->right);
}

void update(int ind, int val, node *v) {
    if (v->tl == v->tr) {
        if (v->tl == ind) {
            v->sum = val;
        }
    } else {
        update(ind, val, v->left);
        update(ind, val, v->right);
        v->sum = v->left->sum + v->right->sum;
    }
}

int main() {
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    node root = {0, 0, 0, NULL, NULL};
    build(0, n-1, a, &root);

    while (m--) {
        int type, i, j; cin >> type >> i >> j;
        if (type == 1) {
            update(i, j, &root);
        } else {
            printf("%lld\n", sum(i, j-1, &root));
        }
    }
}
