#include<bits/stdc++.h>
using namespace std;

// 1 3 4 3 1 3 4 2 4 2
// ( [ ] [ ( [ ] ) ] )

int alternating_depth(int n, int a[]) {
    int ad, temp = 0;
    stack<int> s;
    int prev = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
            s.push(i);
            continue;
        }
        if (i - prev == 1) {
            temp++;
        } else {
            ad = max(ad, temp);
            temp = 0;
        }
        s.pop();
    }
    return ad;
}

int maxlen(int n, int a[], int x) {
    int ans = 0;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            s.push(i);
        } else if (a[i] == 1 + x) {
            int f = s.top(); s.pop();
            ans = max(ans, i - f + 1);
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    printf("%d %d %d\n", alternating_depth(n, a), maxlen(n, a, 1), maxlen(n, a, 3));
}
