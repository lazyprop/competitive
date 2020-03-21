#include<iostream>
using namespace std;

void fact(int);
int mult(int,int[],int);

int main()
{
	int t;
	cin>>t;

	for(int i = 0;i<t;i++)
	{
		int n;
		cin>>n;
		fact(n);
	}
}

void fact(int n)
{
	int ans[500];
	ans[0] = 1;
	int size = 1;

	for (int i = 2;i<=n;i++)
	{
		size = mult(i,ans,size);
	}

	for (int i = size-1;i>=0;i--)
	{
		cout<<ans[i];
	}
	cout<<endl;
}

int mult(int x, int a[], int size)
{
	int carry=0;
	for (int i = 0;i<size;i++)
	{
		int prod = x * a[i]+ carry;
		carry = prod/10;
		a[i] = prod%10;
	}
	while (carry)
	{	
		a[size] = carry % 10;
		carry/=10;
		size++;
	}
	
	return size;
}


	
