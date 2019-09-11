#include<iostream>
#include<vector>
#include<limits>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

string s,t;
int dp[3000][3000];

int lcs(int s1, int t1)
{
	int ans=0;
	if (s1 == -1 or t1 == -1)
	{
		ans = 0;
		return ans;
	}

	else if (dp[s1][t1] >= 0)
	{
		ans = dp[s1][t1];
	}
	else if (s[s1] == t[t1])
	{
		ans = 1 + lcs(s1-1, t1-1);
	}
	else
	{
		ans = max(lcs(s1-1,t1), lcs(s1,t1-1));
	}
	dp[s1][t1] = ans;
	return ans;
}
int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		for (int i = 0; i<3000; i++)
		{
			for (int j = 0; j<3000; j++)
			{
				dp[i][j] = -1;
			}
		}
		// code
		cin>>s;
		cin>>t;
		int s1 = s.size() -1 , t1 = t.size() -1 ;
		lcs(s1,t1);

		int i = s1, j = t1;
		vector<char> l;
		if (dp[s1][t1] > 0) while (i >= 0 and j >= 0)
		{

			if (s[i] == t[j])
			{
				l.push_back(s[i]);
				i--; j--;
			}
			else
			{
				if (i > 0 and j==0)
				{
					i--;
				}
				else if (j>0 and i==0)
				{
					j--;
				}
				else if (i==0 and j==0)
				{
					break;
				}
				else if (dp[i-1][j] > dp[i][j-1])
				{
					i--;
				}
				else
				{
					j--;
				}
			}
			
		}
		if (dp[s1][t1] > 0) for (int i = l.size()-1; i>=0; i--)
		{
			cout<<l[i];
		}
		cout<<endl;
	}
}