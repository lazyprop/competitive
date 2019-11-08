#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		ll n; cin>>n;

		// check if prime
		int prime = 1;
		int p = 0;
		if (n%2 == 0) {prime = 0; p = 2;}
		else for (int i=3; i<=sqrt(n); i+=2)
		{
			if (n%i == 0)
			{
				prime = 0;
				p = i;
				break;
			}
		}

		if (prime)
		{
			cout<<n<<endl;
			return 0;
		}

		ll temp = p, ans = 0;
		while (n % temp == 0)
		{
			if (n/temp ==1)
			{
				ans = p;
			}
			else
			{
				ans = 1;
			}
			temp*=p;
		}
		cout<<ans<<endl;
		return 0;
	}
}