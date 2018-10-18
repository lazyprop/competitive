#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin>>s;
	int t; cin>>t;
	int n = s.length();
	int opt[n][n];
	memset(opt,0,sizeof(opt));

	for (int i=0; i<n; i++)
	{
		for (int j = i; j<n; j++)
		{
			for (int k = i; k<j; k++)
			{
				if (s[k] == s[k+1])
				{
					opt[i][j]++;
				}
			}
		}
	}
	while (t--)
	{
		int l,r; cin>>l>>r;
		l--; r--;
		cout<<opt[l][r]<<endl;
	}
}