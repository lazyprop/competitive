#include<iostream>
using namespace std;

int main()
{
	int o,a,b,n;
	cin>>o>>a>>b>>n;

	int sum=0;

	for (int i = 0;i<n;i++)
	{
		int x;
		cin>>x;
		if (x > a and x<b)
		{
			sum+=1;
		}
	}
	cout<<sum<<endl;
}




