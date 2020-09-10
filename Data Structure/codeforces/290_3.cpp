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
int fl;
vector<int> adj[256], ans, vis(256, 0);
void dfs(int id) {
	vis[id] = 1;
	for (int i : adj[id]) {
		if (vis[i] == 0) dfs(i);
		else if (vis[i] == 1) {
			fl = 1;
			return;
		}
	}
	ans.pb(id);
	vis[id] = 2;
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
		string prev = "", curr;
		for (int i = 0; i < n; i++) {
			cin >> curr;
			int mn = min(sz(curr), sz(prev)), j;
			for (j = 0; j < mn; j++) {
				if (curr[j] != prev[j]) {
					adj[prev[j]].pb(curr[j]);
					break;
				}
			}
			if (j == mn && sz(curr) < sz(prev)) fl = 1;
			prev = curr;
		}
		if (fl) cout << "Impossible";
		else {
			for (int i = 'z'; i >= 'a'; i--) {
				if (vis[i] == 0)
					dfs(i);
			}
			if (fl) cout << "Impossible";
			else for (int i = sz(ans) - 1; i >= 0; i--) cout << (char)ans[i];
		}
		cout << "\n";
	}
	return 0;
}