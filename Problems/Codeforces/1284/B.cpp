#include <bits/stdc++.h>
using namespace std;
 
 

#define ll long long

// THIS PROBLEM SUXXXXX

const ll inf = 1e18;
const int maxn = 1 * 1e5 + 10;


ll res;
std::vector<ll int> arr[maxn];
std::map<ll int, ll int> mp;
std::vector<pair<ll int, ll int>> oof;
std::vector<ll int> x;
std::vector<ll int> fu_cf;
int main()
{
	// ifstream cin("in.txt");
	
    ll int n;
	cin >> n;

	oof.push_back({0, 0});

	for (int i = 1; i <= n; i++)
	{
		ll int len;
		ll int maxim = 0, minim = inf;
		cin >> len;
		for (int j = 0; j < len; j++)
		{
			cin >> res;
			maxim = max(res, maxim);
			minim = min(res, minim);
			arr[i].push_back(res);
		}
		oof.push_back({minim, maxim});
	}


	for (int i = 1; i <= n; i++)
	{
		std::map<ll int, ll int> fkrr;
		fkrr[0]++;

		for(auto j : arr[i])
		{
			fkrr[j]++;
		}
		bool flag = 0;

		for(auto j : arr[i])
		{
			fkrr[j]--;
			if(!fkrr[j]) fkrr.erase(j);
			auto itr = fkrr.rbegin();
			if(itr->first > j) flag = 1; break;
		}

		if(!flag) mp[i]++;
		
		fkrr.clear();
	}

	ll int ans = (n - mp.size()) * n + mp.size() * (n - mp.size());
 
	for(auto i : mp)
	{
		x.push_back(oof[i.first].first);
		fu_cf.push_back(oof[i.first].second);
	}

	sort(x.begin(), x.end());
	sort(fu_cf.begin(), fu_cf.end());
 
	for (int i = 0; i < x.size(); i++)
	{
		auto ind = upper_bound(fu_cf.begin(), fu_cf.end(), x[i]) - fu_cf.begin();
		ans += fu_cf.size() - ind;
	}
	cout << ans;

}