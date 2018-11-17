#include<iostream>
using namespace std;

int dp[1000][1000];
int f(int a,int b)
{
	if (a==1 and b==1)
	{
		return 0;
	}
	if (a<=0 or b<=0)
	{
		return 0;
	}
	if (dp[a][b])
	{
		return dp[a][b];
	}
	int r= 1+max(f(a+1,b-2), f(a-2,b+1));
	dp[a][b] = r;
	return r;
}

int main()
{
	int a,b; cin>>a>>b;
	cout<<f(a,b)<<endl;
}
