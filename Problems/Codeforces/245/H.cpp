#include<iostream>
using namespace std;

int dp[5001][5001];
int ispal[5001][5001];
int n,q;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	cin>>s;
	n = s.size();

	for (int i = 0; i<n; i++)
	{
		dp[i][i] = 1;
		ispal[i][i] = 1;
		ispal[i+1][i] = 1;
	}

	for (int k = 2; k<=n; k++)
	{
		// substring of length k+1
		for (int i = 0; i <= n-k; i++)
		{
			ispal[i][i+k-1] = (s[i] == s[i+k-1]) & ispal[i+1][i+k-2];
			dp[i][i+k-1] = dp[i][i+k-2] + dp[i+1][i+k-1] - dp[i+1][i+k-2] + ispal[i][i+k-1];
		}
	}

	cin>>q;
	while (q--)
	{
		int l,r; cin>>l>>r;
		l--; r--;
		cout<<dp[l][r]<<endl;
	}
	return 0;
}