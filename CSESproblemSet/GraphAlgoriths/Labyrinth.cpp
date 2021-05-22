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
int n, m, dx, dy, sx, sy, X[] = {0, 0, 1, -1}, Y[] = {1, -1, 0, 0};
char adj[1000][1000];
int vis[1000][1000];
char turn[] = {'L', 'R', 'U', 'D'};
bool valid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}
void recover_path(int x, int y, string &s) {
	if (x == sx && y == sy) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + X[i];
		int yy = y + Y[i];
		if (valid(xx, yy) && vis[xx][yy] == vis[x][y] - 1) {
			s += turn[i];
			recover_path(xx, yy, s);
			return;
		}
	}
}
void dfs(int x, int y, int dis) {
	if (vis[x][y] <= dis) return;
	vis[x][y] = dis;
	if (x == dx && y == dy) return;
	for (int i = 0; i < 4; i++) {
		int xx = x + X[i];
		int yy = y + Y[i];
		if (valid(xx, yy) && (adj[xx][yy] == '.' || adj[xx][yy] == 'B')) {
			dfs(xx, yy, dis + 1);
		}
	}
}
void bfs(int x, int y) {
	queue<ar<int, 2>>q;
	vis[x][y] = 1;
	q.push({x, y});
	while (!q.empty()) {
		ar<int, 2> tmp = q.front();
		q.pop();
		x = tmp[0];
		y = tmp[1];
		for (int i = 0; i < 4; i++) {
			int xx = x + X[i];
			int yy = y + Y[i];
			if (valid(xx, yy) && (adj[xx][yy] == '.')) {
				q.push({xx, yy});
				adj[xx][yy] = '#';
				vis[xx][yy] = 1 + vis[x][y];
			}
		}
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
				cin >> adj[i][j];
				if (adj[i][j] == 'A') {
					sx = i;
					sy = j;
				}
				else if (adj[i][j] == 'B') {
					dx = i;
					dy = j;
					adj[i][j] = '.';
				}
			}
		}
		// dfs(sx, sy, 1); //give tle
		bfs(sx, sy);
		if (vis[dx][dy] != 0) {
			string s = "";
			recover_path(dx, dy, s);
			reverse(all(s));
			cout << "YES\n" << sz(s) << '\n' << s << "\n";
		}
		else cout << "NO\n";

	}
	return 0;
}