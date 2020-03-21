#include<bits/stdc++.h>
 
using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n,m,k; cin>>n>>m>>k;
		int h[n];
		for (int i = 0; i<n; i++)
		{
			cin>>h[i];
		}

		string ans="YES";

		if (n==2) if (h[1]-h[0]-m > k) ans="NO";
		
		for (int i = 0; i<n-1; i++)
		{
			m+= h[i] - max(h[i+1]-k, 0);
			if (m<0)
			{
				ans="NO";
				break;
			}
		}
		cout<<ans<<endl;
	}
}