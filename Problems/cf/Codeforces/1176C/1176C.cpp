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
		int a[n];
		for (int i = 0; i<n; i++)
		{
			int temp; cin>>temp;
			if (temp == 4) a[i] = 0;
			if (temp == 8) a[i] = 1;
			if (temp == 15) a[i] = 2;
			if (temp == 16) a[i] = 3;
			if (temp == 23) a[i] = 4;
			if (temp == 42) a[i] = 5;
		}

		int cnt[6] = {};
		for (int i = 0; i<n; i++)
		{
			if (a[i] == 0) cnt[0]++;
			else
			{
				if (cnt[a[i]-1] > 0)
				{
					cnt[a[i]]++;
					cnt[a[i]-1]--;
				}
			}
		}
		cout<<n-(6*cnt[5])<<endl;
	}
}