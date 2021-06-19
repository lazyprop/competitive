#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int primeFactors(int n)
{
    int count = 0;
    if (n%2 == 0) count++;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        if (n%i == 0) count++;
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    return count;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 1) printf("Bob\n");
        else if (primeFactors(n) % 2) printf("Alice\n");
        else print("Bob\n");
    }
}
