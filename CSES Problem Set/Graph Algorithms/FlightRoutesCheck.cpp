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
vector<int> adj[mxn], adj1[mxn], tropo, comp;
int vis[mxn];
void dfs(int id) {
	vis[id] = 1;
	for (int i : adj[id]) {
		if (!vis[i]) dfs(i);
	}
	tropo.pb(id);
}
void dfs1(int id) {
	vis[id] = 1;
	comp.pb(id);
	for (int i : adj1[id]) {
		if (!vis[i]) dfs1(i);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj1[b].pb(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}
		vector<int> ans;
		memset(vis, 0, sizeof(vis));
		reverse(all(tropo));
		for (int i : tropo) {
			if (!vis[i]) {
				dfs1(i);
				ans.pb(comp.back());
				if (sz(ans) == 2) {
					cout << "NO\n";
					cout << ans[1] << " " << ans[0];
					return 0;
				}
				comp.clear();
			}
		}
		cout << "YES\n";
	}
	return 0;
}