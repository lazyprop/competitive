#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = pow(10,5) + 5;

int a[maxn];

unsigned f(int x, int l, int r)
{
	if (!x) return (a[l] & 1) != (a[r] & 1);
	if (r == l) return 0;
	
	if ((a[l] & (1<<x)) == (a[r] & (1<<x)))
	{
		return f(x-1, l, r);
	}

	int ind = -1;
	for (int i = l; i < r; i++)
	{
		if ((a[i] & (1<<x)) != (a[i+1] & (1<<x)))
		{
			ind = i;
			break;
		}
	}

	unsigned int x1 = f(x-1, l, ind), x2 = f(x-1, ind+1, r);
	return (1<<x) + min(x1, x2);
}

int main()
{
	// ifstream cin("in.txt");

	int n; cin>>n;

	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
	}	

	sort(a, a+n, greater<int>());

	cout<<f(30, 0, n-1)<<endl;
}