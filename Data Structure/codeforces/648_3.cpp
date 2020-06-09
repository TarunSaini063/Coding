#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int n;
	cin >> n;
	int a[n], b[n];
	map<int, vector<int>>mp;
	map<pair<int, int>, int>rmp;
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	for (int i = 0; i < n; i++)
	{
		mp[a[i]].pb(i);
	}
	for (int i = 0; i < n; i++)
		mp[b[i]].pb(i);
	for (int i = 0; i < n; i++)
	{
		int p = mp[a[i]][0] - mp[a[i]][1];
		pair<int, int> tmp;
		if (p <= 0)
		{
			tmp = mk(p, n + p);
		}
		else
		{
			tmp = mk(p - n, p);
		}
		rmp[tmp]++;
	}
	int ans = 1;
	for (auto i : rmp) ans = max(ans, i.ss);
	cout << ans << '\n';
	return 0;
}