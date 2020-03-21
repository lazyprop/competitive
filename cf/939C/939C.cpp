#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		long long a[2*n + 2], pre[2*n + 1];
		pre[0] = 0;
		for (int i = 1; i<=n; i++)
		{
			cin>>a[i];
			a[i+n] = a[i];
		}

		for (int i = 1; i<=2*n; i++)
		{
			pre[i] = pre[i-1] + a[i];
		}
		int s,f; cin>>s>>f;
		long long best=0, sum=0;
		int len = f-s;
		
		for (int i = 1; i<=n; i++)
		{
			long long temp = pre[i+len-1] - pre[i-1];
			if (temp > sum)
			{
				sum = temp;
				best = s-(i-1);
				if (best <= 0)
				{
					best+= n;
				}
			}
			if (temp == sum)
			{
				long long t = s-(i-1);
				if (t<=0) t+=n;
				best = min(best,t);
			}
		}
		cout<<best<<endl;
	}
}