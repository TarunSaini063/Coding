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
int n, m, k;
vector<string> arr;
vector<pair<int, int>> tropo;
int vis[500][500], X[] = {1, -1, 0, 0}, Y[] = {0, 0, 1, -1};
bool valid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#') return false;
	return true;
}
void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + X[i];
		int yy = y + Y[i];
		if (valid(xx, yy) && vis[xx][yy] == 0)dfs(xx, yy);
	}
	tropo.pb(mk(x, y));
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		arr = vector<string>(n);
		for (string &i : arr) cin >> i;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] == 0 && arr[i][j] == '.') {
					dfs(i, j);
				}
			}
		}
		// cout << sz(tropo);
		assert(sz(tropo) > k);
		for (int i = 0; i < k; i++) {
			arr[tropo[i].ff][tropo[i].ss] = 'X';
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << "\n";
		}
	}
	return 0;
}