#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n!=0)
	{
		int ans=0;
		for(int i = 1;i<=n;i++)
		{
			ans+=pow(i,2);
		}
		cout<<ans<<endl;
		cin>>n;
	}
}


