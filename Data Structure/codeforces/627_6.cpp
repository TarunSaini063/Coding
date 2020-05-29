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
const int mxn = 2e5 + 1;
vector<int> adj[mxn], arr(mxn), dp(mxn), ans(mxn);
void dfs1(int i, int p)
{
	dp[i] = arr[i];
	for (auto j : adj[i])
	{
		if (j != p)
		{
			dfs1(j, i);
			dp[i] += max(dp[j], 0);
		}
	}
}
void dfs2(int i, int p, int pval)
{
	ans[i] += dp[i] + pval;
	for (auto j : adj[i])
	{
		if (j != p)
		{
			dfs2(j, i, max(ans[i] - max(dp[j], 0), 0));
		}
	}
}
int main(void)
{
	FIO
	int n, u, v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (!arr[i]) arr[i] = -1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		u--, v--;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	dfs1(1, -1);
	dfs2(1, -1, 0);
	for (int i = 1; i <= n; i++) cout << ans[i - 1] << " ";
	ans.clear();
	dp.clear();
	for (int i = 0; i < n; i++) adj[i].clear();
	return 0;
}