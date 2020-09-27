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
int n, m, X[] = {0, 0, 1, -1}, Y[] = {1, -1, 0, 0};
vector<string> adj;
vector<vector<bool>> vis;
bool valid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1) return false;
	return true;
}
bool dfs(int x, int y) {
	bool res = true;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {

		int xx = x + X[i];
		int yy = y + Y[i];
		if (valid(xx, yy) && adj[xx][yy] == '.') {
			res &= dfs(xx, yy);
		}
	}
	return res;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m;
		adj = vector<string>(n);
		for (auto &i : adj) cin >> i;
		vis.assign(n, vector<bool>(m, false));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (adj[i][j] == '.' && !vis[i][j]) {
					if (dfs(i, j)) ans++;
				}
			}
		}
		cout << ans;
	}
	return 0;
}