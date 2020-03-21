#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin>>n;

	//cout<<opt(n)<<endl;
	int ans=0;
	int arr[5] = {100,20,10,5,1};
	for (int i = 0; i<5; i++)
	{
		ans+=n/arr[i];
		n=n%arr[i];
	}
	cout<<ans<<endl;
}