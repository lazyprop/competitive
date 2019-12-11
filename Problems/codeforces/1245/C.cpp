    #include<bits/stdc++.h>
     
    #define MOD %1000000007
    using namespace std;
     
    int dp[1000010];

    int main()
    {
    	int Testcases=1;
    	//cin>>Testcases;
    	while (Testcases--)
    	{
    		// code
    		string s; cin>>s;
    		int n = s.size();
			for (int i = 0; i<n; i++)
			{
				if(s[i] == 'w' or s[i]=='m')
				{
					cout<<0<<endl;
					return 0;
				}
			}
			dp[0] = 1;
			dp[1] = 1;     
    		for (int i = 2; i<=n;i++)
    		{
    			dp[i] = dp[i-1];
    			
    			if (s[i-2] == s[i-1] and (s[i-1]=='u' or s[i-1]=='n'))
    			{
    				dp[i] = dp[i-1] + dp[i-2];
    				dp[i] = dp[i]MOD;
    			}
    		}
     
    		
    		cout<<dp[n] MOD <<endl;
    	}
    }