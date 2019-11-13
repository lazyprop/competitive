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
		int n; cin>>n;
		ll a[n+1], pre[n+1]={},suf[n+2]={};
		ll sum = 0;
		
		for (int i = 1; i<=n; i++)
		{
			cin>>a[i];
			pre[i] = pre[i-1] + a[i];
			sum+= a[i];
		}

		int r[n+5] = {};
		for (int i = n; i>0; i--)
		{
			suf[i] = suf[i+1] + a[i];
			r[i] = r[i+1];
			if (suf[i]==sum/3)
			{
				r[i]++;
			}
		}
		
		ll ans = 0;
		if (sum%3 == 0)
		{
			for (int i=1; i<=n-2; i++)
			{
				if (pre[i] == sum/3) ans+= r[i+2];
			}
		}
		cout<<ans<<endl;
	}
}