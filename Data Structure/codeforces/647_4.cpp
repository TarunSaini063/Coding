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
int main(void)
{
	FIO
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int val[n + 1];
	vector<pair<int, int>> seq;
	for (int i = 1; i <= n; i++)
	{
		cin >> u;
		val[i] = u;
		seq.pb(mk(u, i));
	}
	sort(all(seq));
	set<int> s;
	for (auto i : seq)
	{
		s.clear();
		for (auto u : adj[i.ss])
		{
			if (val[u] <= val[i.ss])s.insert(val[u]);
		}
		if ((int)s.size() != val[i.ss] - 1 || s.find(val[i.ss]) != s.end())
		{
			cout << "-1" << '\n';
			return 0;
		}
	}
	for (auto i : seq) cout << i.ss << ' ';
	cout << '\n';
	return 0;
}