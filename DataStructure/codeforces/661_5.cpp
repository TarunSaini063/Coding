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
ll n, s, tot;
vector<vector<pair<ll, ll>>> adj;
struct cmp {
	bool operator()(pair<ll, ll> p1, pair<ll, ll>p2) {
		ll ben1 = (p1.ff + 1) / 2 * p1.ss;
		ll ben2 = (p2.ff + 1) / 2 * p2.ss;
		return ben1 > ben2;
	}
};
multiset<pair<ll, ll>, cmp> st;
ll dfs(ll id, ll p) {
	ll cnt = 0;
	for (auto i : adj[id]) {
		if (i.ff != p) {
			ll lf = dfs(i.ff, id);
			st.insert(mk(i.ss, lf));
			cnt += lf;
			tot += i.ss * lf;
		}
	}
	if (!cnt)cnt++;
	return cnt;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		ll a, b, w;
		st.clear();
		tot = 0;
		adj.assign(n + 1, vector<pair<ll, ll>>());
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b >> w;
			adj[a].pb(mk(b, w));
			adj[b].pb(mk(a, w));
		}
		dfs(1, -1);
		int ans = 0;
		while (tot > s) {
			ans++;
			auto tmp = *st.begin();
			st.erase(st.begin());
			ll ben = (tmp.ff + 1) / 2 * tmp.ss;
			tot -= ben;
			tmp.ff /= 2;
			if (tmp.ff != 0) st.insert(tmp);
		}
		cout << ans << "\n";
	}
	return 0;
}