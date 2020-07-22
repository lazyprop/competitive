#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        int a[n];
        for (int i = 0; i < n; i++) cin>>a[i];

        int count = 0;
        while (count < n and a[count] == 1) count++;
        if ((count == n) ^ (count % 2)) printf("Second\n");
        else printf("First\n");
    }
}
