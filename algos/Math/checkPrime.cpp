#include<iostream>
using namespace std;

bool checkPrime(int n)
{
	if (n%2 == 0 or n%3 ==0)
	{
		return false;
	}

	for (int i = 5;i*i <= n;i+=6) // every prime number is of form 6k+1 or 6k-1
	{
		if (n%i ==0 or n%i+2 == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	cout<<checkPrime(n)<<endl;
}



