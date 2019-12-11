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
		ll sum = 0;
		int large = 0;
		for (int i = 0; i<n; i++)
		{
			int x; cin>>x;
			sum+=x;
			large = max(large,x);
		}
		
		ll l = large, r = sum;
		ll ans = 0;
		while (l<=r)
		{
			ll m = l + (r-l)/2;
			if (n*m - sum >= m)
			{
				ans = m;
				r = m-1;
			}
			else
			{
				l = m+1;
			}
		}
		cout<<ans<<endl;
	}
}