#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin>>n>>m;
    char a,b,c,d;
    cin>>a;
    for (int i = 0; i < n-1; i++) cin>>c;
    cin>>d;
    for (int i = 0; i < m-1; i++) cin>>b;

    int x = a == '>', y = b=='v', z  = c=='<', w = d=='^';
    if (x == y and y == z and z == w) printf("YES\n");
    else printf("NO\n");
}
