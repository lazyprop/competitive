#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n; cin>>n;
	int ans=0;
	for(int i = 1;i<=sqrt(n);i++)
	{
		ans+=(n/i - i +1);
	}
	cout<<ans;
}

	
	
