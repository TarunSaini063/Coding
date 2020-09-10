#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		ll n, m, u, v, w;
		cin >> n >> m;
		vector<pair<ll, ll>> adj[n + 1];
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			adj[v].pb(mk(u, w));
			adj[u].pb(mk(v, w));
		}
		vector<ll>dis(n + 1, 1e12), par(n + 1);
		dis[1] = 0;
		set<pair<ll, ll>> s;
		s.insert(mk(0, 1));
		while (!s.empty()) {
			v = s.begin()->ss;
			s.erase(s.begin());
			for (auto x : adj[v]) {
				u = x.ff;
				w = x.ss;
				if (dis[v] + w < dis[u]) {
					s.erase(mk(dis[u], u));
					dis[u] = dis[v] + w;
					par[u] = v;
					s.insert(mk(dis[u], u));
				}
			}
		}
		if (dis[n] == 1e12) cout << "-1\n";
		else {
			vector<int> ans;
			for (int x = n; x != 1; x = par[x]) ans.pb(x);
			cout << 1 << " ";
			for (int i = sz(ans) - 1; i >= 0; i--) cout << ans[i] << " ";
			cout << '\n';
		}
		return 0;
	}
}