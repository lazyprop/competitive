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
		int n,wc,hc; cin>>n>>wc>>hc;

		vector<int> a[n+1];
		a[0].push_back(wc);
		a[0].push_back(hc);
		a[0].push_back(0);


		for (int i= 1; i<=n; i++)
		{
			int x,y; cin>>x>>y;
			a[i].push_back(x);
			a[i].push_back(y);
			a[i].push_back(i);
		}

		sort(a,a+n+1);		
		int ind = -1;
		int dp[n+1] ={}, p[n+1]={};

		int huge=0;
		for (int i = 1; i<=n; i++)
		{
			if (wc < a[i][0] and hc < a[i][1])
			{
				dp[i] = 1;
				int large = 0;
				for (int j = 0; j<i; j++)
				{
					if (a[j][0] < a[i][0] and a[j][1] < a[i][1] and dp[i] < dp[j]+1)
					{
						if (dp[j] > large)
						{
							large = dp[j];
							p[i] = j;
						}
					}
					dp[i] = large+1;
				}
				if (dp[i] > huge)
				{
					ind  = i;
				}
			}
		}
		cout<<dp[ind]<<endl;

		stack<int> ans;
		ans.push(a[ind-1][2]);
		int x = p[ind-1];
		while (x)
		{
			ans.push(a[x-1][2]);
			x = p[x-1];
		}

		while (!ans.empty())
		{
			cout<<ans.top()<<" ";
			ans.pop();
		}
		cout<<endl;
	}
}