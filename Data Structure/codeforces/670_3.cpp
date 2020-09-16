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
const int mxn = 1e5 + 10;
vector<int>adj[mxn], size(mxn, 1), par(mxn);
int fl = 0, n;
int dfs(int id, int p) {
	size[id] = 1;
	par[id] = p;
	for (int i : adj[id]) {
		if (i == p) continue;
		dfs(i, id);
		size[id] += size[i];
	}
	return size[id];
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int  a, b;
		fl = 0;
		cin >> n;
		for (int i = 0; i <= n; i++) adj[i].clear(), size[i] = 0;
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, 0);
		for (int i = 1; i <= n && fl == 0; i++) {
			if (size[i] * 2 == n) {
				for (int j : adj[i]) {
					if (j != par[i]) {
						cout << i << " " << j << "\n";
						cout << j << " " << par[i] << "\n";
						fl = 1;
						break;
					}
				}
			}
		}
		if (fl == 0) {
			cout << a << " " << b << "\n";
			cout << a << " " << b << "\n";
		}
	}
	return 0;
}