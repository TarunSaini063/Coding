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
struct egde {
	int to, from, wt;
};
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m, a, b, c, s, x;
		cin >> n >> m;
		int inf = 1e9;
		vector<int> dis(n + 1, inf), par(n + 1);
		vector<egde>adj(m);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			adj[i].to = a;
			adj[i].from = b;
			adj[i].wt = c;
		}
		cin >> s;
		dis[s] = 0;
		for (int i = 1; i <= n; i++) {
			x = -1;
			int fin = 0;
			for (int j = 0; j <= m - 1; j++) {
				if (dis[adj[j].from] < inf) {
					if (dis[adj[j].to] > dis[adj[j].from] + adj[j].wt) {
						dis[adj[j].to] = dis[adj[j].from] + adj[j].wt;
						x = adj[j].to;
						par[adj[j].to] = adj[j].from;
						fin = 1;
					}
				}
			}
			if (fin == 0) break;
		}
		vector<int> path;
		path.pb(x);
		for (int i = par[x]; i != x; i = par[i]) path.pb(i);
		reverse(all(path));
		for (int i : path) cout << i << " ";
		cout << "\n";

	}
	return 0;
}