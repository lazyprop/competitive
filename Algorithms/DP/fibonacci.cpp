#include<iostream>
using namespace std;

unsigned long long fib(int n, unsigned long long memo[])
{
	if (memo[n-1])
	{
		return memo[n-1];
	}
	unsigned long long f = fib(n-1,memo) + fib(n-2,memo);
	memo[n-1] = f;
	return f;
}

int main()
{
	int n; cin>>n;
	unsigned long long memo[n];
	for (int i = 0; i<n; i++)
	{
		memo[i] = 0;
	}
	memo[0] = 1;
	memo[1] = 1;

	cout<<fib(n,memo)<<endl;
}
