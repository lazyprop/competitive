#include<iostream>
using namespace std;

int sum(int n)
{
	int s=0;
	while (n>0)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}
int main()
{
	int k; cin>>k;
	int count=1;
	int n;
	for (n=19; count<k; n=n)
	{

		n+=9;
		if (sum(n) == 10)
		{
			count++;
		}
		//n+=9;
	}
	cout<<n<<endl;
}

