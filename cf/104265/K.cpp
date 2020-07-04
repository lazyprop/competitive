#include <bits/stdc++.h>
using namespace std;

const int maxn = 700;
pair<int, string> dp[maxn][maxn];
string s;

pair<int, string> f(int l, int r)
{
    if (l > r) return make_pair(10000, "fda");
    string temp = "";
    temp+= s[l];

    if (l == r) return make_pair(1, temp);
    if (dp[l][r].first) return dp[l][r];

    dp[l][r] = make_pair(1000, "");
    
    for (int i = l; i < r; i++)
    {
        int x;
        string cont;

        pair<int, string> left = f(l,i), right = f(i+1, r);
        if (left.second == right.second)
        {
            x = left.first;
            cont = left.second;
        }
        else
        {
            x = left.first + right.first;
            cont = left.second + right.second;
        }
        if (x < dp[l][r].first)
        {
            dp[l][r] = make_pair(x, cont);
        }
    }

    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n; cin>>n;
    cin>>s;

    cout<<f(0,n-1).first<<endl;
}
