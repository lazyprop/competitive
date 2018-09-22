#include<iostream>
using namespace std;

bool checkPrime(int n)
{
	for (int i = 5;i*i<=n;i+=6)
	{
		if (n%i == 0 or n%i+2==0)
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
	

		cout<<"working\n";
		while (n%2 ==0)
		{
			n/=2;
			cout<<2<<" ";
		}

		while (n%3 == 0)
		{
			n/=3;
			cout<<3<<" ";
		}

		for (int i = 5;n>1;i+=6)
		{
			if (checkPrime(i))
			{
				cout<<i<<endl;
				while (n%i == 0)
				{
					n/=i;
					cout<<i<<" ";
				}
			}
			if (checkPrime(i+2))
			{
				while (n%i+2 == 0)
				{
					n/=i+2;
					cout<<i+2<<" ";
				}
			}
			if (n==1) break;

		}
	
	cout<<endl;
}


