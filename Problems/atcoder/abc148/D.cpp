#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;

	set<int> seen;
	seen.insert(0);
	int count = 0;
	for (int i = 0; i<n; i++)
	{
		int x; cin>>x;
		if (seen.find(x-1) != seen.end() and seen.find(x) == seen.end())
		{
			seen.insert(x);
			count++;
		}
	}

	if (count == 0)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<n-count<<endl;
	}
}