#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	int x[n],y[n];
	for (int i = 0; i<n; i++)
	{
		cin>>x[i]>>y[i];
	}
	
	int ans=0;
	for (int i = 0; i<n-1;i++)
	{
		ans+=min(abs(x[i]-x[i+1]),abs(y[i]-y[i+1]));
	}
	cout<<ans<<endl;
}


