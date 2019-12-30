#include<bits/stdc++h>
using namespace std;

int main()
{
	int n; cin>>n;
	int a[n];
	vector<int> zeroes;
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
		if (a[i] == 0)
		{
			zeroes.push_back(i);
		}
	}

	while (true)
	{
		random_shuffle(zeroes.begin(), zeroes.end());

		
	}
}