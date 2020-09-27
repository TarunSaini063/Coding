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
vector<int> adj[mxn];
int vis[mxn], par[mxn], se = -1, ss ;
bool dfs(int id, int p) {
	vis[id] = 1;
	par[id] = p;
	for (int i : adj[id]) {
		if (i == p) continue;
		if (vis[i] == 0) {
			if (dfs(i, id)) return true;
		}
		else if (vis[i] == 1) {
			ss = i;
			se = id;
			return true;
		}
	}
	vis[id] = 2;
	return false;
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
			adj[b].pb(a);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0 && dfs(i, -1)) {
				break;
			}
		}
		if (se == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			vector<int> ans;
			ans.pb(ss);
			for (int i = se; i != ss; i = par[i]) {
				ans.pb(i);
			}
			ans.pb(ss);
			cout << sz(ans) << "\n";
			for (int i : ans	)cout << i << " ";
		}
	}
	return 0;
}