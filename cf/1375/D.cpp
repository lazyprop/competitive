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
        int a[n+3], freq[n+3] = {};
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }

        vector<int> sol;
        for (int x = 0; x < n; x++)
        {
            int mex = x;
            for (int i = x+1; i < n; i++)
            {
                if (!freq[i])
                {
                    mex = i;
                    break;
                }
            }
            for (int i = x+1; i < n; i++)
            {
                if (a[i] == x)
                {
                    // replace with current mex
                    freq[a[i]--];
                    sol.push_back(i);
                    // get new mex
                    for (int j = mex; j < n; j++)
                    {
                        if (!freq[j])
                        {
                            mex = j;
                            break;
                        }
                    }
                }
            }

            if (a[x] == x) continue;
            freq[x]++;
            sol.push_back(x);
        }

    int l = sol.size();
    printf("%d\n", l);
    for (auto u: sol)
    {
        printf("%d ",u+1);
    }
    printf("\n");
    }
}
