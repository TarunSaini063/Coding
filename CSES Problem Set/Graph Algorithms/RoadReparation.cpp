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
ll n, m, a, b, w;
const int mxn = 1e5 + 1;
vector<ll>par, size;
struct edge {
	ll to, from, wt;
	bool operator<(edge other) {
		return other.wt >= wt;
	}
};
ll root(ll x) {
	if (x == par[x]) return x;
	return x = root(par[x]);
}
void uni(ll x, ll y) {
	x = root(x);
	y = root(y);
	if (size[x] > size[y]) swap(x, y);
	par[x] = y;
	size[y] += size[x];
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<edge> v(m);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> w;
			v[i].from = a;
			v[i].to = b;
			v[i].wt = w;
		}
		sort(all(v));
		for (int i = 0; i < n + 1; i++) par.pb(i), size.pb(1);
		ll ans = 0, cnt = 0;
		for (int i = 0; i < m; i++) {
			// cout << v[i].wt << "\n";
			if (root(v[i].from) != root(v[i].to)) {
				ans += v[i].wt;
				uni(v[i].from, v[i].to);
				cnt++;
				if (cnt == n - 1) break;
			}
		}
		if (cnt != n - 1) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";

	}
	return 0;
}