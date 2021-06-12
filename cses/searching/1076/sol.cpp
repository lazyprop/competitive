#include <bits/stdc++.h>
using namespace std;

int n, k;
multiset<int> hi, lo;

void ins(int x) {
    int med = *lo.rbegin(); // current median
    if (x > med) {
        hi.insert(x);
        if (hi.size() > k / 2) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    } else {
        lo.insert(x);
        if (lo.size() > (k + 1) / 2) {
            hi.insert(*lo.rbegin());
            lo.erase(lo.find(*lo.rbegin()));
        }
    }

}

void rm(int x) {
    if (hi.find(x) != hi.end()) hi.erase(hi.find(x));
    else lo.erase(lo.find(x));
    if (lo.empty()) {
        lo.insert(*hi.begin());
        hi.erase(hi.begin());
    }
}

int main() {
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    lo.insert(a[0]);

    for (int i = 1; i < k; i++) {
        ins(a[i]);
    }

    printf("%d ", *lo.rbegin());

    for (int i = k; i < n; i++) {
        if (k == 1) {
            ins(a[i]);
            rm(a[i-k]);
        } else {
            rm(a[i-k]);
            ins(a[i]);
        }
        printf("%d ", *lo.rbegin());
    }
    printf("\n");
}
