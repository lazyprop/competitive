#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;

	for (int x = 0;x<t;x++)
	{
		int n,ans=0;
		cin>>n;

		for (int i = n;i>0;i-=2)
		{
			ans+=i*i;
		}
		cout<<ans<<endl;
	}	
}

