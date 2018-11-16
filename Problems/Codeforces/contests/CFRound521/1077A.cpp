#include<iostream>
using namespace std;

int main()
{
	int t; cin>>t;
	while (t--)
	{
		long long a,b,c;
		cin>>a>>b>>c;

		long long  m = c/2;
		cout<<a*(c-m) - b*m<<endl;
	}
}

