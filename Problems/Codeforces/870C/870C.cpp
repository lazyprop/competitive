#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		int n; cin>>n;
		int ans;
		if (n<4)
		{
			ans=-1;			
		}
		else if (n%2 == 1 and n<13 and n!=9)
		{
			ans=-1;
		}
		
		else if (n%4 == 0)
		{
			ans=n/4;
		}
		else if (n%4 == 1)
		{
			ans = 1 + (n-9)/4;
		}
		else if (n%4 == 2)
		{
			ans = 1 + (n-6)/4;
		}
		else if (n%4 == 3)
		{
			ans = 2 + (n-15)/4;
		}
		cout<<ans<<endl;
	}
	return 0;
}