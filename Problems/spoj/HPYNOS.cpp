#include<iostream>
#include<math.h>
using namespace std;

int getSum(int n)
{
	unsigned long int sum=0;
	while (n>0)
	{
		sum+= pow(n%10,2);
		n/=10;
	}
	return sum;
}
int search(int a[],int n,int l)
{
	for (int i = 0;i<l;i++)
	{
		if (a[i] == n)
		{
			return 1;
			break;
		}
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int s[10000];

	int count=0;
	while(getSum(n) != 1)
	{
		s[count] = n;
		n = getSum(n);
		if (search(s,n,count) == 1)
		{
			ans=-1;
			break;
		}
		count++;
	}
	count++;

	if (ans!=-1)
	{
		cout<<count;
	}
	else
	{
		cout<<ans;
	}
}



