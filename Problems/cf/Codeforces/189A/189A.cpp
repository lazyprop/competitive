#include<iostream>
using namespace std;

int dp[1000000];
int opt(int n, int a, int b, int c)
{

	if (dp[n])
	{
		return dp[n];
	}

	if (n<0)
	{
		int ans= -1000000;
	}
	if (n==0)
	{
		return 0;
	}
	int x=-1000000,y=-10000000,z=-10000000;
	if (n>=a)
	{
		x= opt(n-a,a,b,c);
	}
	if (n>=b)
	{
		y = opt(n-b,a,b,c);
	}
	if (n>=c)
	{
		z = opt(n-c,a,b,c);
	}
	int ans=max(max(1+x,1+y),1+z);
	dp[n] = ans;
	return ans;
}


int main()
{
	int n; cin>>n;
	int a,b,c; cin>>a>>b>>c;
	
	cout<<opt(n,a,b,c)<<endl;
}


	

