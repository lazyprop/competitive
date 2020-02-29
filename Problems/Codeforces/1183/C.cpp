#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int Q; cin>>Q;
	while (Q--)
	{
		long long k,n,a,b; cin>> k >> n >> a >> b;

		int l = 0, r = n, best = -1;
		while (l <= r)
		{
			int m = l + (r-l)/2;

			if (k - m * a - (n-m) * b > 0)
			{
				l = m + 1;
				best = m;
			}
			else
			{
				r = m - 1;
			}
		}
		cout<<best<<endl;
	}
}