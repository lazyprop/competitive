#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

matrix mult(matrix& a, matrix& b) {
    matrix res;
    int n = a.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

int main() {
    int n, b, k, x; cin >> n >> b >> k >> x;
    matrix mat(x, vector<int>(x));
}
