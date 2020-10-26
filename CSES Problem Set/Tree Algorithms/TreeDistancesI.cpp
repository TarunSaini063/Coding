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
const int mxn = 2e5 + 1;
vector<int> adj[mxn];
int in[mxn], out[mxn];
void dfs(int id, int p = -1) {
	int ans = 0;
	for (int i : adj[id]) {
		if (i == p) continue;
		dfs(i, id);
		in[id] = max(in[id], in[i] + 1);
	}
}
void dfs1(int id, int p = -1) {
	int mx1 = -1, mx2 = -1;
	for (int i : adj[id]) {
		if (i == p) continue;
		if (mx1 == -1 || in[mx1] < in[i]) {
			mx2 = mx1;
			mx1 = i;
		}
		else if (mx2 == -1 || in[mx2] < in[i]) {
			mx2 = i;
		}
	}

	for (int i : adj[id]) {
		if (i == p) continue;
		if (mx1 != -1 && i != mx1) {
			out[i] = in[mx1] + 2;
		}
		else if (mx2 != -1) {
			out[i] = in[mx2] + 2;
		}
		out[i] = max(out[id] + 1, out[i]);
		dfs1(i, id);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1);
		dfs1(1);
		for (int i = 1; i <= n; i++) cout << max(in[i], out[i]) << " ";
	}
	return 0;
}