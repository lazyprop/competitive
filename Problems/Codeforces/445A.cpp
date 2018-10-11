#include<iostream>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	char arr[n][m];
	for (int i = 0;  i<n; i++)
	{
		for (int j = 0; j<m ; j++)
		{
			cin>>arr[i][j];
			//cout<<arr[i][j];
		}
	}
	for (int i = 0; i<n;i++)
	{
		for (int j = 0; j<m;j++)
		{
			if (arr[i][j] == '-')
                        {
                                cout<<'-';
                        }
                        else
                        {
                                if (j%2== 0)
                                {
                                        if (i%2==0) cout<<'B';
                                        else cout<<'W';
                                }
                                else
                                {
                                        if (i%2==0) cout<<'W';
                                        else cout<<'B';
                                }
                        }
		}
		cout<<endl;
	}

}

