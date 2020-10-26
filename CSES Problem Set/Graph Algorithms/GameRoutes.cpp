#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 1e5 + 1;
vector<int> adj[mxn], par(mxn), dis(mxn);
int vis[mxn], n, fl = 0;
void dfs(int id) {
	if (id == n) {
		dis[id] = 1;
		return;
	}
	vis[id] = 1;
	for (int i : adj[id]) {
		if (vis[i] == 0) {
			par[i] = id;
			dfs(i);
		}
		dis[id] = (dis[id] + dis[i]) % mod;
	}
	vis[id] = 2;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
		}
		dfs(1);
		cout << dis[1] << "\n";
	}
	return 0;
}