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
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> adj[n + 1];
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		queue<int> q;
		q.push(1);
		int  par[n + 1] = {0};
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i : adj[u]) {
				if (par[i] == 0) {
					par[i] = u;
					q.push(i);
				}
			}
		}
		if (!par[n]) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			vector<int>ans;
			ans.pb(n);
			for (int i = par[n]; i != 1; i = par[i]) {
				ans.pb(i);
			}
			ans.pb(1);
			cout << sz(ans) << "\n";
			for (int i = sz(ans) - 1; i >= 0; i--) cout << ans[i] << " ";
		}
	}
	return 0;
}