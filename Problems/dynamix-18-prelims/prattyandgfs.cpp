#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void sort(int arr[][2], int arrsum[], int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n-1; j++)
		{
			if (arrsum[j] > arrsum[j+1])
			{
				// swap arr
				int temp = arr[j][0];

				arr[j][0] = arr[j+1][0];
				arr[j+1][0] = temp;

				temp = arr[j][1];

				arr[j][1] = arr[j+1][1];
				arr[j+1][1] = temp;

				// swap arrsum
				temp = arrsum[j];
				arrsum[j] = arrsum[j+1];
				arrsum[j+1] = temp;
			}
		}
	}
}


int main()
{
	int n,b; cin>>n>>b;
	int arr[n][2], arrsum[n];
	
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i][0]>>arr[i][1];
		arrsum[i] = arr[i][0] + arr[i][1];
	}
	sort(arr,arrsum,n); 
	int sum=0;

	int i = 0;
	for ( i = 0; i<n; i++)
	{
		sum=0;
		for (int j = 0; j<i; j++)
		{
			sum+=arr[j][0] + arr[j][1];
		}
		sum+= arr[i][0]/2 + arr[i][1];
		
		if (sum > b)
		{
			break;
		}
	}
	cout<<i;
	
}

