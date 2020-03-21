#include<bits/stdc++.h>
using namespace std;

const int maxn = 102;
const int maxk = 12;
const int mod = pow(10,8);

int n1, n2, k1, k2;
int dp[maxn][maxn][maxk][3];

int f(int i, int j, int k, int x)
{

	if (i > n1 or j > n2) return 0;
	if (x == 1 and k > k1) return 0;
	if (x == 2 and k > k2) return 0;
	
	if (i == n1 and j == n2) return dp[i][j][k][x] = 1;;

	if (dp[i][j][k][x] >= 0) return dp[i][j][k][x];

	dp[i][j][k][x] = 0;
	if (x == 1)
	{
		dp[i][j][k][x]+= f(i+1, j, k+1, 1);
		dp[i][j][k][x]+= f(i, j+1, 1, 2);
	}
	else
	{
		dp[i][j][k][x]+= f(i+1, j, 1, 1);
		dp[i][j][k][x]+= f(i, j+1, k+1, 2);
	}

	dp[i][j][k][x]%= mod;

	return dp[i][j][k][x];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	cin>>n1>>n2>>k1>>k2;

	memset(dp, -1, sizeof(dp));

	cout<<(f(1,0,1,1) + f(0,1,1,2))%mod<<endl;
}