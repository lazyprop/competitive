    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
    #define ull unsigned long long
    int main()
    {
    	//ifstream cin("in.txt");
    	//ofstream cout("out.txt");
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
     
    	int Testcases=1;
    	//cin>>Testcases;
    	while (Testcases--)
    	{
    		// code
    		
    		int n,k; cin>>n>>k;
    		ll a[n+1];
    		ll pre[n+1] = {};
    		for (int i = 1; i<=n; i++)
    		{
    		    cin>>a[i];
    		    pre[i] = pre[i-1] + a[i];
    		}
    		
            ll maxSS[n + 1] = {};
            ll best = 0;
         
            for(int i = 1; i <= n - k + 1; i++)
            {
                maxSS[i] = maxSS[i - 1];
                if(pre[i + k - 1] - pre[i - 1] > best)
                {
                    best = pre[i + k - 1] - pre[i - 1];
                    maxSS[i] = i;
                }
            }
         
            int maxA = 0, maxB = 0;
            best = 0;
         
            for(int i = k + 1; i <= n - k + 1; i++)
            {
                ll x = pre[i + k - 1] - pre[i - 1];
                if(x + pre[maxSS[i - k] + k - 1] - pre[maxSS[i - k] - 1] > best)
                {
                    best = x + pre[maxSS[i - k] + k - 1] - pre[maxSS[i - k] - 1];
                    maxA = maxSS[i - k];
                    maxB = i;
                }
            }
            cout<<maxA<<" "<<maxB<<endl;
        }
    }