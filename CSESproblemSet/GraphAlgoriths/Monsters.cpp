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
const int mxn = 1e3 + 1;
char adj[mxn][mxn], turn[] = {'L', 'R', 'U', 'D'};
int x, y = -1, n, m, dis1[mxn][mxn], dis2[mxn][mxn], X[] = {0, 0, 1, -1}, Y[] = {1, -1, 0, 0}, vis[mxn][mxn];
vector<ar<int, 2>> mos;
bool valid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}
void recover_path(int x1, int y1, string &s, int dis[mxn][mxn]) {
	if (x1 == x && y1 == y) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x1 + X[i];
		int yy = y1 + Y[i];
		if (valid(xx, yy) && dis[xx][yy] == dis[x1][y1] - 1) {
			s += turn[i];
			recover_path(xx, yy, s, dis);
			return;
		}
	}
}
void bfs(vector<ar<int, 2>> mos, int dis[mxn][mxn]) {
	queue<ar<int, 2>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			dis[i][j] = 1e9;
	}
	memset(vis, 0, sizeof(vis));
	for (auto i : mos) {
		q.push(i);
		dis[i[0]][i[1]] = 1;
		vis[i[0]][i[1]] = 1;
	}
	while (!q.empty()) {
		ar<int, 2> tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = tmp[0] + X[i];
			int yy = tmp[1] + Y[i];
			if (valid(xx, yy) && adj[xx][yy] == '.' && vis[xx][yy] == 0) {
				vis[xx][yy] = 1;
				dis[xx][yy] = 1 + dis[tmp[0]][tmp[1]];
				q.push({xx, yy});
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
				cin >> adj[i][j];
				if (adj[i][j] == 'M') mos.pb({i, j}), adj[i][j] = '.';
				if (adj[i][j] == 'A') x = i, y = j, adj[i][j] = '.';
			}
		}
		bfs({{x, y}}, dis1);
		bfs(mos, dis2);
		int dx, dy = -1;
		for (int i = 0; i < n; i++) {
			if (dis1[i][0] < dis2[i][0]) {
				if (dy == -1 || dis1[dx][dy] > dis2[i][0])dx = i, dy = 0;
			}
			if (dis1[i][m - 1] < dis2[i][m - 1]) {
				if (dy == -1 || dis1[dx][dy] > dis2[i][m - 1])dx = i, dy = m - 1;
			}
		}
		for (int i = 0; i < m; i++) {
			if (dis1[0][i] < dis2[0][i]) {
				if (dy == -1 || dis1[dx][dy] > dis2[0][i])dx = 0, dy = i;
			}
			if (dis1[n - 1][i] < dis2[n - 1][i]) {
				if (dy == -1 || dis1[dx][dy] > dis2[n - 1][i])dx = n - 1, dy = i;
			}
		}
		if (dy != -1) {
			cout << "YES\n";
			string s = "";
			recover_path(dx, dy, s, dis1);
			reverse(all(s));
			cout << sz(s) << "\n" << s << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}