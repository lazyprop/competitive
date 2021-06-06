#include <bits/stdc++.h>
using namespace std;

const int maxn = 302, inf = 1e8;
int pref[maxn], arr[maxn];

int f(int i, int j) {
}

int main() {
    int n, p; cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }
}
