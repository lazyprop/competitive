#include<iostream>
using namespace std;
 
int main()
{
	int n; cin>>n;
	int sum = 1,i = 2;
 
	while (sum <= n)
	{
		sum += i;
		i++;
	}
	i-=2;
	cout<<i<<endl;
	int j;
	sum=0;
	for (j = 1; j<i; j++)
	{
		cout<<j<<" ";
		sum+=j;
	}
	cout<<n-sum<<endl;;
}   