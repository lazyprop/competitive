#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		long long x = 0, sum = 0;
		for (int i = 0; i<n; i++)
		{
			long long k; cin>>k;
			x^=k;
			sum+= k;
		}
		if (x*2 == sum)
		{
			cout<<0<<endl<<endl;
		}
		else
		{
			cout<<2<<endl;
			cout<<x<<" "<<sum+x<<endl;			
		}
	}
}