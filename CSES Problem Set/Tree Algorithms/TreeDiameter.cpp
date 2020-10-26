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
int n, ans, x, dis[mxn];
int dfs(int id, int p, int h) {
	for (int i : adj[id]) {
		if (i == p) continue;
		dfs(i, id, h + 1);
	}
	if (ans <= h) {
		ans = h;
		x = id;
	}
}
void dfs1(int id, int p) {
	for (int i : adj[id]) {
		if (i == p) continue;
		dfs1(i, id);
		ans = max(ans, dis[i] + dis[id] + 1);
		dis[id] = max(dis[id], dis[i] + 1);
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
		// dfs(1, -1, 0);
		// dfs(x, -1, 0);
		dfs1(1, -1);
		cout << ans << '\n';
	}
	return 0;
}