// wrong solution (TLE)
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
int col[mxn], ans[mxn];
set<int> dfs(int id , int p) {
	set<int> s;
	s.insert(col[id]);
	for (int i : adj[id]) {
		if (i != p) {
			set<int> tmp = dfs(i, id);
			for (int i : tmp) s.insert(i);
		}
	}
	ans[id] = s.size();
	return s;
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
		for (int i = 1; i <= n; i++) cin >> col[i];
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, -1);
		for (int i = 1; i <= n; i++)cout << ans[i] << " ";
	}
	return 0;
}