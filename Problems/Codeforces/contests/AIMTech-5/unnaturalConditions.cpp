#include<iostream>
using namespace std;

int sum(int n)
{
	int s = 1;
	while (n>9)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}
int main()
{
	int m,n;
	cin>>n>>n;
	int s = sum(n);
	int i = 0;
	while (true)
	{
		int flag=0,j=0;
		while(true)
		{
			if (sum(i) >=n and sum(j) >=n and sum(j) + sum(i) <=m)
			{
				flag=0;
				break;
			}
			j++;
		}
		if (flag==0)
		{
			break;
		}
		i++;
	}
}

		
	
		
