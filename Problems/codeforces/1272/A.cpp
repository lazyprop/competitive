#include<bits/stdc++.h>
using namespace std;

int main()
{
	//ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int a[3];
		for (int i = 0; i<3; i++) cin>>a[i];
		sort(a,a+3);

		long long dist = a[2] - a[1] + a[1] - a[0] + a[2] - a[0];

		if (dist - 4 < 0)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<dist-4<<endl;
		}
		
	}	
}