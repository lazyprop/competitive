#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    if (s == "RRS" or s == "SRR") {
        printf("2\n");
        return 0;
    }
    if (s == "SSS") {
        printf("0\n");
        return 0;
    }
    if (s == "RRR") {
        printf("3\n");
        return 0;
    }
    printf("1\n");
}
