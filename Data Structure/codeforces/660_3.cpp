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
int n, m, fl;
vector<vector<int>> adj;
vector<int> p, h, sm, bad;
void solve(int id, int p1) {
	sm[id] = p[id - 1];
	int bd = 0;
	for (auto i : adj[id]) {
		if (i != p1) {
			solve(i, id);
			sm[id] += sm[i];
			bd += bad[i - 1];
		}
	}
	if (h[id - 1] > sm[id] || h[id - 1] < -sm[id] || (sm[id] + h[id - 1]) % 2 == 1) {
		fl = 1;
	}
	bad[id - 1] = (sm[id] - h[id - 1]) / 2;
	if (bad[id - 1] > p[id - 1] + bd) fl = 1;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		adj.assign(n + 1, vector<int>());
		p = vector<int>(n);
		h = vector<int>(n);
		bad = vector<int>(n);
		sm = vector<int> (n + 1);
		fl = 0;
		for (auto &i : p ) cin >> i;
		for (auto &i : h) cin >> i;
		int u, v;
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		solve(1, -1);
		if (fl) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}