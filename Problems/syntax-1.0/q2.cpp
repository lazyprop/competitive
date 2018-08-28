// https://www.hackerrank.com/contests/syntax-v1-0-programming-prelims/challenges/how-many-routes
#include<iostream>
using namespace std;

void findpaths (int c,int a[][2]);

int main()
{
	int r = 0;
    int m,n,count=0;
    cin>>m>>n;
    m++;

    int a[2][n],b[m];
    for(int i = 0; i < m;i++)
    {
        b[i]=0;
        for(int j = 0; j < 2;j++)
        {
            cin>>a[j][i];
        }
    }
    
    
    int acon[n][n-1];
	
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<n-1;j++)
		{
			acon[i][j] = 0;
		}
	} 	   
    
    for (int i = 0;i < n;i++)
    {
    	int len = 0;
    	for (int j = 0;j<m;j++)
    	{
    		if (a[0][j] == i)
    		{
    			acon[i-1][len] = a[1][j];
    			len++;
			}
		}
	}
	
	for (int i = 0;i<n-1;i++)
	{
		if (a[0][i] == 2)
		{
			r++;
		}
		else if (a[0][i] == 0)
		{
			break;
		}
		else
		{
			findpaths(a[0][i],acon);
		}
	}
	
}


void findpaths(int c,int *acon)
{
	
}
    
