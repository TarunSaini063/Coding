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
vector<int> adj1[mxn], adj2[mxn], com, tropo;
int vis[mxn];
void dfs(int id) {
	vis[id] = 1;
	for (int i : adj1[id]) {
		if (!vis[i]) dfs(i);
	}
	tropo.pb(id);
}
void dfs1(int id) {
	vis[id] = 1;
	com.pb(id);
	for (int i : adj2[id]) {
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
			adj1[a].pb(b);
			adj2[b].pb(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) dfs(i);
		}
		reverse(all(tropo));
		memset(vis, 0, sizeof(vis));
		int ans[n + 1], k = 1;
		for (int i : tropo) {
			if (!vis[i]) {
				dfs1(i);
				for (int i : com) ans[i] = k;
				k++;
				com.clear();
			}
		}
		cout << k - 1 << "\n";
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	}
	return 0;
}