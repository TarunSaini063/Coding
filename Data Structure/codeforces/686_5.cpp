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
vector<int> adj[mxn], cycle;
int vis[mxn], par[mxn], start, ed;
bool dfs(int id, int p) {
	par[id] = p;
	vis[id] = 1;
	for (int i : adj[id]) {
		if (i == p) continue;
		if (vis[i] == 0) {
			if (dfs(i, id)) return true;
		}
		else if (vis[i] == 1) {
			ed = i;
			start = id;
			return true;
		}
	}
	vis[id] = 2;
	return false;
}
int dfs2(int id, int p) {
	vis[id] = 1;
	int size = 1;
	for (int i : adj[id]) {
		if (i == p) continue;
		if (!vis[i]) {
			size += dfs2(i, id);
		}
	}
	return size;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, -1);
		for (int i = start; ; i = par[i]) {
			cycle.pb(i);
			if (i == ed) break;
		}
		for (int i = 0; i <= n; i++) vis[i] = 0;
		for (int i : cycle) vis[i] = 1;
		ll subtree = 0, other = 0;
		for (int i : cycle) {
			ll size = dfs2(i, -1);
			other += 2 * size * (n - size);
			subtree += size * (size - 1) / 2;
		}
		cycle.clear();
		cout << other / 2 + subtree << '\n';
		for (int i = 0; i <= n; i++)
		{
			adj[i].clear();
			vis[i] = 0;
		}
	}
	return 0;
}