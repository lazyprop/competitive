#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if (a>0)
		{
			ans+=a;
		}
	}
	cout<<ans;
}


