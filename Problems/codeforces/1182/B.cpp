#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int h,w; cin>>h>>w;
	int a[h][w] = {};
	for (int i = 0; i<h; i++)
	{
		for (int j = 0; j<w; j++)
		{
			char x; cin>>x;
			if (x == '*')
			{
				a[i][j] = 1;
			}
		}
	}

	string ans = "YES";
	int row[h] = {}, col[w] = {};
	int yes = 0;
	for (int i = 0; i<h; i++)
	{
		for (int j = 0; j<w; j++)
		{
			if (a[i][j])
			{
				row[i]++;
				col[j]++;
				yes++;
			}
		}
	}

	if (yes < 5)
	{
		cout<<"NO\n";
		return 0;
	}

	for (int i = 0; i<h; i++)
	{
		if (row[i])
		{
			int l = 0, r = w-1;
			while (!a[i][l] and l < w) l++;
			while (!a[i][r] and r >= 0) r--;

			for (int j = l; j<=r; j++)
			{
				if (!a[i][j])
				{
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}

	for (int i = 0; i<w; i++)
	{
		if (col[i])
		{
			int l = 0, r = h-1;
			while (!a[l][i] and l < h) l++;
			while (!a[r][i] and r >= 0) r--;

			for (int j = l; j<=r; j++)
			{
				if (!a[j][i])
				{
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}

	int flag = 0;
	int l = 0, r = h-1;

	while (!row[l] and l < h) l++;
	while (!row[r] and r >= 0) r--;

	if (r - l < 2)
	{
		cout<<"NO\n";
		return 0;
	}

	for (int i = l; i<=r; i++)
	{
		if (!row[i])
		{
			cout<<"NO\n";
			return 0;
		}
		if (row[i] > 1) flag++;
	}
	if (flag != 1)
	{
		cout<<"NO\n";
		return 0;
	}

	flag = 0; l = 0; r = w-1;
	while (!col[l] and l < w) l++;
	while (!col[r] and r >= 0) r--;

	if (r - l < 2)
	{
		cout<<"NO\n";
		return 0;
	}

	for (int i = l; i<=r; i++)
	{
		if (!col[i])
		{
			cout<<"NO\n";
			return 0;
		}
		if (col[i] > 1) flag++;
	}
	if (flag != 1)
	{
		cout<<"NO\n";
		return 0;
	}

	cout<<"YES\n";
	return 0;
}