#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	string s;
	int ones=0;
	for (int i = 0; i<n; i++)
	{
		cin>>s[i];
		if (s[i] == '1')
		{
			ones++;
		}
	}
	int opt[n];
	for (int i = 0; i<n; i++)
	{
		opt[i] = 0;
	}
	for (int i = 0; i<n;i++)
	{
		int count;
		if (s[i] == '0')
		{
			for (int j = 0; j<i; j++)
			{
				if (s[j]==s[i])
				{
					count=j-1;
					i+=j-1;
					break;
				}
				opt[j] = count;
			}
			
		}		

	}
	int m=0;
	for (int i = 0; i<n; i++)
	{
		m = max(opt[i],m);
	}
	cout<<ones<<endl;
	cout<<m+ones<<endl;
}