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
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		string s; cin>>s;

		int l[n+1]={}, r[n+2]={};
		int last = -1;
		for (int i = 1; i<=n; i++)
		{
			l[i] = l[i-1]+1;
			if (s[i-1] == '1')
			{
				l[i]++;
				last = i;
			}
		}

		for (int i = n; i>0; i--)
		{
			r[i] = r[i+1]+1;
			if (s[i-1]=='1') r[i]++;
		}

		int ans =0;
		for (int i = 1; i<=n; i++)
		{
			if (s[i-1]=='1')
			{
				ans = max(ans,max(2*i, l[i]+r[i+1]));
			}
		}
		for (int i = n; i>0; i--)
		{
			if (s[i-1]=='1')
			{
				ans = max(ans,max(2*(n-i+1), l[i-1]+r[i]));
			}
		}

		if (l[n] == n) ans = n;
		else if (l[n] - l[n-1] == 2)
		{
			ans = 2*n;
		}

		else if (r[1] - r[2] == 2)
		{
			ans = 2*n;
		}
		cout<<ans<<endl;
	}
}