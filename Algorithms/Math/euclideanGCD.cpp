#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	//base case
	if (a == b)
	{
		return a;
	}

	if (b==0)
	{
		return a;
	}
	
	if (a>b)
	{
		return gcd(b, a%b);
	}

	if (a<b)
	{
		return gcd(a,b%a);
	}
}

int main()
{
	int a,b;
	cin>>a>>b;

	cout<<gcd(a,b)<<endl;
}






