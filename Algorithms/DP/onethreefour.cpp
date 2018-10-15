#include<iostream>
using namespace std;

unsigned long long topDown(int n, unsigned long long memo[])
{
	if (memo[n])
	{
		return memo[n];
	}
	unsigned long long t = topDown(n-1,memo) + topDown(n-3,memo) + topDown(n-4,memo);
	memo[n] = t;
	return t;
}

unsigned long long bottomUp(int n, unsigned long long memo[])
{
	if (memo[n])
	{
		return memo[n];
	}
	for (int i = 4; i<=n; i++)
	{
		memo[i] = memo[i-1] + memo[i-3] + memo[i-4];
	}
	return memo[n];
}

int main()
{
	int n; cin>>n;
	unsigned long long memo[n+1];
	
	for (int i = 0; i<n+1; i++)
	{
		memo[i] = 0;
	}

	memo[0]=1;
	memo[1]=1;
	memo[2]=1;
	memo[3]=2;

	cout<<topDown(n,memo)<<endl;
	cout<<bottomUp(n,memo)<<endl;
}


