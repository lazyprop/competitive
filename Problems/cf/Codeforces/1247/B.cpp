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

	int T=1; cin>>T;
	while (T--)
	{
		int n,k,d; cin>>n>>k>>d;
		int a[n];
		for (int i = 0; i<n; i++) cin>>a[i];

		int freq[1000001] = {};
		int ans = 0;
		for (int i = 0; i<d; i++)
		{
			if (!freq[a[i]]) ans++;
			freq[a[i]]++;
		}
		//cout<<ans<<endl;
		int idk[n]= {};
		idk[0] = ans;

		for (int i = d; i<n; i++)
		{
			if (freq[a[i]] == 0)
			{
				ans++;
			}
			freq[a[i]]++;
			if (freq[a[i-d]] == 1)
			{
				ans--;
			}
			freq[a[i-d]]--;
			idk[i-d+1] = ans;
			//cout<<ans<<" ";
		}
		//cout<<endl;
		ans = INT_MAX;
		for (int i = 0; i<n-d+1; i++)
		{
			ans = min(ans,idk[i]);
		}
		cout<<ans<<endl;
	}
}