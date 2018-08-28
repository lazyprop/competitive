// Matched Brackets

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for (int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	// Max Depth
	int md = 0;
	int index = 0;

	int d = 0;
	for (int i = 0;i<n;i++)
	{
		if (arr[i] == 1)
		{
			d++;
		}
		else
		{
			if (d > md)
			{

				index = i;
				md = d;
			}

			d=0;
		}
	}
	cout<<md<<" "<<index<<" ";

	// Max Length
	
	vector<int> a;
	vector<int> b;
	
	for (int i = 0;i<n;i++)
	{
		if (arr[i] == 1)
		{
			a.push_back(i++);
		}
		else
		{
			b.push_back(i-a[a.size()-1] + 1);
		}

	}
	int maxx=0, ind;
	for (int i = 0;i<b.size();i++)
	{
		cout<<a[i]<<" ";
		if (b[i] > maxx)
		{
			maxx = b[i];
			ind=i;
			//cout<<maxx<<" "<<ind<<endl;
		}
	}


	
	cout<<maxx+2<<" "<<a[ind]++<<endl;

}



