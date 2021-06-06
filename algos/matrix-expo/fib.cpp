#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct matrix {
    ll mat[2][2] = {};

    matrix() {}
    matrix(ll b[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat[i][j] = b[i][j];
            }
        }
    }

    matrix operator*(matrix& other) {
        matrix result;
        for (int i = 0; i < 2; i++) {
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    result.mat[i][k] += mat[i][j]*other.mat[j][k];
                    result.mat[i][k] %= Mod;
                }
            }
        }
        return result;
    }
};
