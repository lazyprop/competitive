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
	vector<int> c;
	vector<int> db;

	for (int i = 0;i<n;i++)
	{
		if (arr[i] == 1)
		{
			a.push_back(i+1);
		}
		else
		{
			b.push_back(i+1);
		}
	}
	int max = 0;
	for (int i = 0;i<a.size();i++)
	{
		c.push_back(b[i] - a[i] + 2);
		db.push_back(a[i]);

		if (b[i] - a[i] + 2> max)
		{
			max = b[i] - a[i] +2 ;
		}

	}
	
	int len = 0;
	index = 0;
	for (int i = 0;i<c.size();i++)
	{
		if (c[i] == max)
		{
			cout<<c[i] + 1<<" "<<db[i]- 1;
			break;
		}
	}
	cout<<endl;

}



