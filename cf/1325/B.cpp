#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        unordered_set<int> seen;

        for  (int i = 0; i < n; i++)
        {
            int x; cin>>x;
            seen.insert(x);
        }
        cout<<seen.size()<<endl;
    }
}

