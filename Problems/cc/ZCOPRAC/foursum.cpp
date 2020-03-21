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

	int n,t; cin>>n>>t;
	int a[n];
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
	}

	ll ans = 0;
	int freq[t+1] = {};
	
	for (int k = 0; k<n; k++)
	{

		for (int l = k+1; l<n; l++)
		{
			if (a[l] + a[k] <= t)
			{
				ans+= freq[t-a[l]-a[k]];
			}
		}
		for (int i = 0; i<k; i++)
		{
			if (a[i] + a[k] <= t)
			{
				freq[a[i]+a[k]]++;
			}
		}
	}
	cout<<ans<<endl;
}