#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n,k; cin>>n>>k;

		int d = 2*k + 1;
		int q = n/d;
		int r = n%d;

		if (r!=0)
		{
			q++;
		}
		else
		{
			r = 2*k;
		}

		cout<<q<<endl;
		for (int i = r/2 + 1; i<=n; i+=d)
		{
			cout<<i<<" ";
		}
	}
}