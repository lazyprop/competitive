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
		string a; cin>>a;		
		if (n==1 and k>0)
		{
			cout<<0<<endl;
			return 0;
		}
		int flag=0;
		for (int i = 0, count=0; i<n and count<k; i++)
		{
			if (i>0)
			{
				if (a[i] != '0')
				{
					a[i] = '0';
					count++;
				}
			}
			else
			{
				if (k>0 and a[0]!= '1')
				{
					a[0] = '1';
					count++;
				}
			}
		}
		for (int i = 0; i<n; i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
}