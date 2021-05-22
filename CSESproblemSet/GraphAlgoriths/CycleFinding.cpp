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
const int mxn = 2501;
vector<ar<ll, 2>> adj[mxn];
int par[mxn], vis[mxn];
ll dis[mxn];
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
			ll a, b, c;
			cin >> a >> b >> c;
			adj[a].pb({c, b});
			// par[b] = a;
		}
		int ss = -1;
		for (int i1 = 0; i1 < n; i1++) {
			int x = 0;
			ss = -1;
			for (int i = 1; i <= n; i++) {
				for (ar<ll, 2> tmp : adj[i]) {
					int to = tmp[1];
					ll len = tmp[0];
					if (dis[i] < 1e18) {
						if (dis[to] > dis[i] + len) {
							dis[to] = dis[i] + len;
							par[to] = i;
							ss = to;
							x = 1;
						}
					}
				}
			}
			if (!x) break;
		}
		if (ss == -1) cout << "NO\n";
		else {
			cout << "YES\n";
			vector<int> ans;
			for (int i = 0; i < n; i++)ss = par[ss];
			for (int i = ss; ; i = par[i]) {
				ans.pb(i);
				if (i == ss && sz(ans) > 1) break;
			}
			reverse(all(ans));
			for (int i : ans) cout << i << " ";
		}
	}
	return 0;
}