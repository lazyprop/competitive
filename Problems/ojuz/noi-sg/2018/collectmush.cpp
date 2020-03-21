#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ifstream cin("in.txt");

	int r, c, d, k; cin>>r>>c>>d>>k;

	int mush[r+1][c+1] = {}, diff[r+1][c+1] = {};
	int diffrow[r+1] = {};

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char ch; cin>>ch;
			
			mush[i][j] = 0;

			if (ch == 'M') mush[i][j] = 1;

			else
			{
				if (ch == 'S')
				{
					int start = max(0, j - d), end = min(c, j + d + 1);

					diff[i][start]++;
					diff[i][end]--;

					start = max(0, i-d); end = min(r, i + d + 1);

					if (end - start > 1)
					{
						diffrow[start]++;
						diffrow[end]--;
						diffrow[i]--;
					}
				}
			}
		}
	}

	int ans = 0, bal = 0;
	for (int i = 0; i < r; i++)
	{
		bal+= diffrow[i];
		
		cout<<diffrow[i];
		for (int j = 0; j < c; j++)
		{
			bal+= diff[i][j];
			
			// cout<<diff[i][j]<<" ";
			// cout<<bal<<" "; 
			if (bal >= k and mush[i][j] == 1) ans++;
		}
		cout<<endl;
	}

	cout<<ans<<endl;
}