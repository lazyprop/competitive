#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;

	for (int i = 0;i<t;i++)
	{
		int n;
		cin>>n;

		while (n)
		{
			cout<<n%10;
			n/=10;
		}
		cout<<endl;
	}
	cout<<endl;
}

