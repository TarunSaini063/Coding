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
vector<ar<ll, 2>> adj1[mxn], adj2[mxn];
ll d1[mxn], d2[mxn], n;
void dij(int id, ll dis[mxn], vector<ar<ll, 2>> adj[mxn]) {
	set<ar<ll, 2>> st;
	for (int i = 1; i <= n; i++) dis[i] = 1e18;
	dis[id] = 0;
	st.insert({0ll, id});
	while (!st.empty()) {
		int u = (*st.begin())[1];
		st.erase(st.begin());
		for (ar<ll, 2> it : adj[u]) {
			int to = it[1];
			ll len = it[0];
			if (dis[to] > dis[u] + len) {
				st.erase({dis[to], to});
				dis[to] = dis[u] + len;
				st.insert({dis[to], to});
			}
		}
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int  m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj1[a].pb({c, b});
			adj2[b].pb({c, a});
		}
		dij(1, d1, adj1);
		dij(n, d2, adj2);
		ll ans = 1e18;
		for (int i = 1; i <= n; i++) {
			for (ar<ll, 2> tmp : adj1[i]) {
				ans = min(ans, d1[i] + d2[tmp[1]] + tmp[0] / 2);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}