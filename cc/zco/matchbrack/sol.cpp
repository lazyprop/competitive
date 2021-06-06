#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string seq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) seq += '(';
        if (x == 2) seq += ')';
        if (x == 3) seq += '[';
        if (x == 4) seq += ']';
    }

    stack<int> st, alt;
    int ad = 0, bal = 0;

    for (int i = 0; i < n; i++) {
        if (seq[i] == '(' or seq[i] == '[') {
            if (st.empty()) alt.push(bal);
            else if (seq[i] == st.top()) alt.push(bal);

            bal++;
            st.push(i);
        } else {
            bal--;
            if (bal == alt.top()) alt.pop();
            st.pop();
        }
        ad = max(ad, (int) alt.size());

        printf("%d\n", alt.size());
    }

    printf("%d\n", ad);
}
