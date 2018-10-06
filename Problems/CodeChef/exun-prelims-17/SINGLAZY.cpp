#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int arr[c][b][a];
	for (int i= 0; i<c; i++)
	{
		for (int j = 0; j<b; j++)
		{
			for (int k = 0; k<a; k++)
			{
				cin>>arr[i][j][k];
			}
		}
	}

	int q; cin>>q;
	while (q--)
	{
		int x1,y1,z1; cin>>x1>>y1>>z1;
		int x2,y2,z2; cin>>x2>>y2>>z2;

		int sum = 0;
		for (int k = 0; k<x2-x1; k++)
		{
			for (int j=0; j<y2-y1; j++)
			{
				for (int i = 0; i<z2-z1; i++)
				{
					sum+=arr[i+x1][y1+j][z1+k];
				}
			}
		}
		cout<<sum<<endl;
	}
}


