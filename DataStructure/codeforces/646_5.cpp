#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 2e5 + 1;
ll a[mxn], b[mxn], c[mxn];
ll ans;
vector<ll> adj[mxn];
pair<ll, ll> dfs(ll id, ll p, ll mn)
{
	ll on = 0, ze = 0;
	if (b[id] != c[id])
	{
		if (b[id])on++;
		else ze++;
	}
	for (auto i : adj[id])
	{
		if (i == p) continue;
		auto p1 = dfs(i, id, min(mn, a[id]));
		on += p1.ff;
		ze += p1.ss;
	}
	if (a[id] < mn)
	{
		int tp = min(on, ze);
		ans += 2 * tp * a[id] * 1ll;
		on -= tp;
		ze -= tp;
	}
	return mk(on, ze);
}
int main(void)
{
	FIO
	ll n, x, y;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i + 1] >> b[i + 1] >> c[i + 1];
	}
	for (ll i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	auto p = dfs(1, -1, INT_MAX);
	if (p.ff || p.ss) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}