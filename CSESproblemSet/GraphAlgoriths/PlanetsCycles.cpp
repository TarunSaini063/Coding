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
vector<int> adj[mxn], tropo, cycle;
int vis[mxn], t[mxn], cyclenum[mxn], cyclesize[mxn];
void dfs(int i) {
	vis[i] = 1;
	if (!vis[t[i]]) dfs(t[i]);
	tropo.pb(i);
}
void dfs2(int id, int num) {
	vis[id] = 0;
	cyclenum[id] = num;
	cycle.pb(id);
	for (int i : adj[id]) {
		if (vis[i]) {
			dfs2(i, num);
		}
	}
}
int main(void)
{
	FIO
	int T = 1;
	// cin >> t;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> t[i + 1];
			adj[t[i + 1]].pb(i + 1);
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) dfs(i);
		}
		int num = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (vis[tropo[i]]) {
				dfs2(tropo[i], num);
				cyclesize[num] = sz(cycle);
				cycle.clear();
				num++;
			}
		}
		vector<int> ans(n + 1);
		for (int i : tropo) {
			if (t[i] == i) ans[i] = 1;
			else if (cyclenum[i] == cyclenum[t[i]]) {
				ans[i] = cyclesize[cyclenum[i]];
			}
			else ans[i] = ans[t[i]] + 1;
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	}
	return 0;
}