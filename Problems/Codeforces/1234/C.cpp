#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n+1][2];
		string s; cin>>s;
		for (int i = 0; i<n; i++)
		{
			a[i][0] = s[i] - '0';
		}
		a[n][1] = 0;
		cin>>s;
		for (int i = 0; i<n; i++)
		{
			a[i][1] = s[i] - '0';
		}

		int row=0;
		int i;
		for (i = 0; i<n; i++)
		{
			if (a[i][row] >= 3)
			{
				if (a[i][row^1] <=2)
				{
					break;
				}
				else row^=1;
			}
		}
		
		if (i == n and row==1)
		{
			cout<<"YES"<<endl;;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}