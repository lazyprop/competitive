#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n; cin>>n;
	int x[n];
	for (int i = 0; i<n; i++)
	{
		cin>>x[i];
	}

	int q; cin>>q;
	int m[q];
	for (int i = 0; i<q; i++)
	{
		cin>>m[i];
	}

	sort(x,x+n);
	
	for (int i = 0; i<q; i++)
	{
		int* p = bsearch(

