#include<iostream>
using namespace std;

int main()
{
	int n,q; cin>>n>>q;
	int a[n];
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
	}
	
	while (q--)
	{
		int L, R, k; cin>>L>>R>>k;
		for (int i = L; i<=R; i++) k/=a[i-1];
		cout<<k<<endl;
	}
}



