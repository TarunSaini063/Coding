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

	int n, a, b, c;
	cin >> n;
	map<pair<int, int>, vector<int>> mp;
	int cnt[n + 1] = {0};
	int ans[n + 1];
	for (int i = 0; i < n - 2; i++)
	{
		cin >> a >> b >> c;
		cnt[a]++;
		cnt[b]++;
		cnt[c]++;
		mp[ {a, b}].pb(c);
		mp[ {b, c}].pb(a);
		mp[ {a, c}].pb(b);
		mp[ {b, a}].pb(c);
		mp[ {c, b}].pb(a);
		mp[ {c, a}].pb(b);
	}
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 1)
		{
			v1.pb(i);
		}
		else if (cnt[i] == 2)
		{
			v2.pb(i);
		}
	}
	int f = v1[0];
	int g = v2[0];
	int vis[n + 1] = {0};
	if ((mp[ {f, g}]).size())
	{
		ans[0] = f;
		ans[1] = g;
		vis[f] = 1;
		vis[g] = 1;
		for (int i = 2; i < n; i++)
		{
			for (auto j : mp[ {ans[i - 1], ans[i - 2]}]) {
				if (vis[j] == 0) {
					ans[i] = j;
					vis[j] = 1;
				}
			}
		}
	}
	else {

		ans[0] = f;
		g = v2[1];
		ans[1] = v2[1];
		vis[f] = 1;
		vis[g] = 1;
		for (int i = 2; i < n; i++)
		{
			for (auto j : mp[ {ans[i - 1], ans[i - 2]}])
			{
				if (vis[j] == 0)
				{
					ans[i] = j;
					vis[j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}