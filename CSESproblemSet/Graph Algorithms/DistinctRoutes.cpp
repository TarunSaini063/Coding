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
const int mxn = 5e2 + 1;
vector<int> adj[mxn];
int vis[mxn], par[mxn], n, m;
vector<vector<int>> ans;
bool dfs(int id, int p) {
	vis[id] = 1;
	par[id] = p;
	if (id == n) {
		vector<int> tmp;
		for (int i = n; i != 1; i = par[i]) {
			tmp.pb(i);
		}
		tmp.pb(1);
		reverse(all(tmp));
		ans.pb(tmp);
		vis[id] = 0;
		return true;
	}
	for (int i : adj[id]) {
		if (!vis[i]) {
			if (dfs(i, id)) {
				return true;
			}
			else {
				vis[i] = 0;
			}
		}
	}
	vis[id] = 0;
	return false;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, -1);
		cout << sz(ans) << '\n';
		for (auto &i : ans) {
			cout << sz(i) << '\n';
			for (auto &j : i) {
				cout << j << ' ';
			}
			cout << "\n";
		}
	}
	return 0;
}