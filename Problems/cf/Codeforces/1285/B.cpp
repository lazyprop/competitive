#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = pow(10,5) + 5;

ll a[maxn];

ll kadane(int l, int r)
{
	ll max_so_far = 0, max_ending_here = 0; 
	for (int i = l; i <= r; i++) 
	{ 
	   max_ending_here = max_ending_here + a[i]; 
	   if (max_ending_here < 0) 
	       max_ending_here = 0; 

	   else if (max_so_far < max_ending_here) 
	       max_so_far = max_ending_here; 
	} 
	return max_so_far; 
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;

		ll sum = 0;
		ll maxele = INT_MIN;

		for (int i = 0; i<n; i++)
		{
			cin>>a[i];

			sum+= a[i];
			maxele = max(maxele, a[i]);
		}
		
		ll best = max(kadane(0,n-2), kadane(1,n-1));
		

		if (best == 0) best = maxele;

		if (best < sum) cout<<"YES\n";
		else cout<<"NO\n";

	}	
}