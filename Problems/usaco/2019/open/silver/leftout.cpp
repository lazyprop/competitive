#include<bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int grid[maxn][maxn];
int rowonecount[maxn];
int columnonecount[maxn];

int count(int i1, int j1, int i2, int j2, int x)
{
	int ans = 0;
	for (int i = i1; i<= i2; i++)
	{
		for (int j = j1; j<=j2; j++)
		{
			if (grid[i][j] == x)
			{
				ans++;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ifstream cin("leftout.in");
	ofstream cout("leftout.out");

	int n; cin>>n;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			char x; cin>>x;
			grid[i][j] = x=='R';
		}
	}

	rowonecount[0] = grid[1][1];
	columnonecount[0] = grid[1][1];
	for (int i = 0; i<n; i++)
	{
		if (grid[i][0])
		{
			for (int j = 0; j<n; j++)
			{
				grid[i][j] = 1-grid[i][j];
				if (i)
				{
					rowonecount[i]+= grid[i][j];
				}
			}
		}
	}
	
	for (int j = 0; j<n; j++)
	{
		if (grid[0][j])
		{
			for (int i = 0; i<n; i++)
			{
				grid[i][j] = 1-grid[i][j];
				if (j)
				{
					columnonecount[j]+=grid[i][j];
				}
			}
		}
	}

	if (count(1,1, n-1,n-1, 0) == 0)
	{
		cout<<"1 1\n";
		return 0;
	}

	if (count(1,1,n-1,n-1, 1) == n-1)
	{
		for (int i = 1; i<n; i++)
		{
			for (int j = 1; j<n; j++)
			{
				if (rowonecount[j] == n-1)
				{
					cout<<1<<" "<<j+1<<endl;
					return 0;
				}
				if (columnonecount[i] == n-1)
				{
					cout<<i+1<<" 1\n";
					return 0;
				}
			}
		}
		cout<<-1<<endl;
	}

	if (count(1,1,n-1,n-1,1) != 1)
	{
		cout<<-1<<endl;
		return 0;
	}

	for (int i = 1; i<n; i++)
	{
		for (int j = 1; j<n; j++)
		{
			if (grid[i][j])
			{
				cout<<i+1<<" "<<j+1<<endl;
				return 0;
			}
		}
	}
}