#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct min_deg {
    set<pii> data;
    int* deg;
}

vector<int> get_cur_level(min_deg &md) {
    pii top = md.data.begin();
    md.data.erase(top);
    vector<int> nodes;
    nodes.push_back(top->second);
    while (!md.data.empty()) {
        pii t = md.data.begin();
        if (t->first > top->first) break;
        nodes.push_back(t->second);
        md.data.erase(t);
    }
    return nodes;
}

void push(min_deg &md, pii p) {
    md.data.insert(p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;

        vector<int> adj[n+1];
        int deg[n+1] = {};
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        //set<pii> st; // (degree, nodeid)
        //priority_queue<pii, vector<pii>, std::greater<pii>> pq;

        for (int i = 1; i <= n; i++) {
            //st.insert({deg[i], i});
            //pq.push({deg[i], i});
            md.push({deg[i], i});
        }

        int cur = n;
        int val[n+1];

        //while (!st.empty()) {
        while (cur > 0) {
            pii t = pq.top(); pq.pop();
            int d = t.first;

            vector<int> temp;
            temp.push_back(t.second);

            vector<int> layer; // all nodes with the current minimum degree
            layer.push_back(t.second);

            while (!pq.empty()) {
                pii p = pq.top(); pq.pop();
                printf("%d %d\n", p.first, p.second);
                if (p.first > d) break;
                layer.push_back(p.second);
            }

            // for each of these nodes, reduce their degrees
            // and assign them numbers
            for (auto v: temp) {
                printf("reduce degree of %d: %d -> %d\n", v, deg[v], deg[v]-1);
                deg[v]--;
                val[v] = cur--;
            }

            // for all nodes in layer, assign them numbers, remove them from the
            // graph. reduce degree of all of their neighbors
            for (auto u: layer) {
                val[u] = cur--;
                for (auto v: adj[u]) {
                    // get pair {v, deg[v]} from the queue
                    deg[v]--;
                }
            }

            // for each of these nodes, append the pair with the new degree
            // into the set
            for (auto v: temp) {
                if (deg[v] > 0) pq.push({deg[v], v});
            }
        }

        int md = 0;
        for (int i = 1; i <= n; i++) {
            int cd = 0;
            for (auto u : adj[i]) {
                cd += (val[i] > val[u]);
            }
            md = max(md, cd);
        }

        for (int i = 1; i <= n; i++) {
            printf("%d ", val[i]);
        }
        printf("\n");
    }
}
