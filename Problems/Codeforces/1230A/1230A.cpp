#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int a[4];
		for (int i = 0; i<4; i++)
		{
			cin>>a[i];
		}
		string ans = "NO";
		sort(a,a+4);
		
		if (a[0] + a[3] == a[1] + a[2]) ans="YES";
		else if (a[3] == a[0] + a[1] + a[2]) ans = "YES";		
		cout<<ans<<endl;
	}
}