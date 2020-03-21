#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		string s;
		cin>>s;

		int n = s.size();
		int x = 0, y=0;
		
		string ans = "NO";
		for (int i = 1; i<n; i++)
		{
			if (s[i] == 'B' and s[i-1] == 'A')
			{
				if (x==0) i++;
				x++;
			}
			else if (s[i] == 'A' and s[i-1] == 'B' and x>0)
			{
				y++;
			}
		}
		if (x>0 and y>0) ans = "YES";
		x = 0; y = 0;
		for (int i = 1; i<n; i++)
		{
			if (s[i] == 'A' and s[i-1] == 'B')
			{
				if (y==0) i++;
				y++;
			}
			else if (s[i] == 'B' and s[i-1] == 'A' and y>0)
			{
				x++;
				i++;
			}
		}
		if (x>0 and y>0) ans = "YES";

		cout<<ans<<endl;
	}
}