#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[3] = {};
	for (int i = 0; i<2; i++)
	{
		int x; cin>>x;
		a[x-1]++;
	}
	for (int i = 0; i<3; i++)
	{
		if (!a[i])
		{
			cout<<i+1;
			return 0;
		}
	}
}