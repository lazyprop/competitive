#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
multiset<int> hi, lo;
ll hisum, losum;

void ins(int x) {
    int med = *lo.rbegin(); // current median
    if (x > med) {
        hisum += x;
        hi.insert(x);
        if (hi.size() > k / 2) {
            losum += *hi.begin();
            lo.insert(*hi.begin());
            hisum -= *hi.begin();
            hi.erase(hi.begin());
        }
    } else {
        losum += x;
        lo.insert(x);
        if (lo.size() > (k + 1) / 2) {
            hisum += *lo.rbegin();
            hi.insert(*lo.rbegin());
            losum -= *lo.rbegin();
            lo.erase(lo.find(*lo.rbegin()));
        }
    }

}

void rm(int x) {
    if (hi.find(x) != hi.end()) {
        hisum -= x;
        hi.erase(hi.find(x));
    }
    else {
        losum -= x;
        lo.erase(lo.find(x));
    }

    if (lo.empty()) {
        losum += *hi.begin();
        lo.insert(*hi.begin());
        hisum -= *hi.begin();
        hi.erase(hi.begin());
    }
}

ll cost() {
    ll med = *lo.rbegin();

    return (ll) hisum - (med * hi.size())
         + (med * lo.size()) - (ll) losum;
}

int main() {
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    losum += a[0];
    lo.insert(a[0]);

    for (int i = 1; i < k; i++) {
        cost();
        ins(a[i]);
    }

    printf("%lld ", cost());

    for (int i = k; i < n; i++) {
        if (k == 1) {
            ins(a[i]);
            rm(a[i-k]);
        } else {
            rm(a[i-k]);
            ins(a[i]);
        }
        printf("%lld ", cost());
    }
    printf("\n");
}
