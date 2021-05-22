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
int n, m;
const int mxn = 1e5 + 1;
int vis[mxn];
vector<int> adj[mxn];
void dfs(int id) {
	vis[id] = 1;
	for (int i : adj[id]) {
		if (!vis[i]) dfs(i);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m ;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int comp = 0;
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
				ans.pb(i);
				comp++;
			}
		}
		comp--;
		cout << comp << "\n";
		if (comp) {
			for (int i = 0; i < sz(ans) - 1; i++) {
				cout << ans[i] << " " << ans[i + 1] << '\n';
			}
		}
	}
	return 0;
}