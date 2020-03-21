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
		int n,m; cin>>n>>m;

		ll k; cin>>k;

		ll l = 1, r = 1LL * n*m + 1;

		while (l<r)
		{
			ll mid = l + (r-l)/2;

			ll x = 0;
			for (int i = 1; i<=n; i++)
			{
				x+= min((ll)m,(mid-1)/i);
			}

			if (x<k) l=mid+1;
			else r = mid;
		}
		cout<<l-1<<endl;
	}
}