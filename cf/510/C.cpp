#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, int> first_uncommon_char(string a, string b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i]) {
            return make_pair(a[i] - 'a', b[i] - 'a');
        }
    }
    if (a.size() > b.size()) {
        return make_pair(-2, -2);
    }
    return make_pair(-1, -1);
}

vector<int> adj[26], topsort;
bool visited[26], in_stack[26], cycle = false;

void dfs(int u) {
    in_stack[u] = true;
    visited[u] = true;
    for (auto v: adj[u]) {
        if (in_stack[v]) {
            cycle = true;
            return;
        }

        if (!visited[v]) dfs(v);
    }
    in_stack[u] = false;
    topsort.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n; cin >> n;
    string names[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    // find first uncommon character
    // do a dfs on them, starting from top and moving to the bottom
    // the characters after the first uncommon character don't matter


    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            pair<int, int> p = first_uncommon_char(names[i], names[j]);
            if (p.first > -1) adj[p.first].push_back(p.second);
            if (p.first == -2) {
                printf("Impossible\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!visited[i]) dfs(i);
    }
    
    if (cycle) {
        printf("Impossible\n");
        return 0;
    }

    reverse(topsort.begin(), topsort.end());
    for (auto u: topsort) {
        printf("%c", (char) u + 'a');
    }
    printf("\n");
}
