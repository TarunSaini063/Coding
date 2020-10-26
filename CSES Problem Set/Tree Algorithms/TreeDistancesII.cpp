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
const int mxn = 2e5 + 1;
vector<int> adj[mxn];
ll sz[mxn], dis[mxn], out[mxn], ans[mxn], n;
void dfs(int id, int p) {
	sz[id] = 1;
	for (int i : adj[id]) {
		if (i != p) {
			dis[i] = dis[id] + 1;
			dfs(i, id);
			sz[id] += sz[i];
		}
	}
}
void dfs1(int id, int p, ll tot) {
	ans[id] = tot;
	for (int i : adj[id]) {
		if (i != p) {
			dfs1(i, id, tot + n - 2 * sz[i]);
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
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, -1);
		ll tot = 0;
		for (int i = 1; i <= n; i++) tot += dis[i];
		dfs1(1, -1, tot);
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	}
	return 0;
}