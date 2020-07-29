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
        vector<int> odd, even;
        for (int i = 1; i <= 2*n; i++)
        {
            int x; cin>>x;
            if (x%2) odd.push_back(i);
            else even.push_back(i);
        }

        vector<pair<int, int> > ans;
        for (int i = 0, l = odd.size(); i+1 < l; i+=2)
        {
            ans.push_back({odd[i], odd[i+1]});
        }
        for (int i = 0, l = even.size(); i+1 < l; i+=2)
        {
            ans.push_back({even[i], even[i+1]});
        }

        for (int i = 0; i < n-1; i++)
        {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }
}
