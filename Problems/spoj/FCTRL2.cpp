#include<iostream>
using namespace std;

int mult(int,int[],int);
int main()
{
	int t;
	cin>>t;
	for (int x =0;x<t;x++)
	{

		int ans[500];
		ans[0] = 1;
		int size = 1;

		int n;
		cin>>n;

		for (int i = 2;i<=n;i++)
		{
			size = mult(i,ans,size);
		}

		for (int i = size-1; i>=0;i--)
		{
			cout<<ans[i];
		}

		cout<<endl;
	}
}

int mult(int n, int ans[], int size)
{
	int carry = 0;

	for (int i = 0;i<size;i++)
	{
		int prod = ans[i] * n + carry;
		carry = prod/10;
		ans[i] = prod%10;
	}

	while (carry)
	{
		ans[size] = carry%10;
		carry/=10;
		size++;
	}
	return size;

}

