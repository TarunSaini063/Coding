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
int n, m, dn, dm, cn, cm, X[] = {1, -1, 0, 0}, Y[] = {0, 0, 1, -1}, mat[1000][1000], ans = 0, mag[1000][1000];
string arr[1000];
bool valid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.' && mat[x][y] == 0) return true;
	return false;
}
void dfs(int x, int y) {
	mat[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + X[i];
		int ny = y + Y[i];
		if (valid(nx, ny)) dfs(nx, ny);
	}
}
int main(void)
{
	FIO
	int t = 1;
	while (t--)
	{
		cin >> n >> m;
		cin >> cn >> cm >> dn >> dm;
		cn--, cm--, dn--, dm--;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (arr[dn][dm] == '#') {
			cout << "-1\n";
			return 0;
		}
		ans = -1;
		dfs(cn, cm);
		if (mat[dn][dm] == 1) {
			cout << "0\n";
			return 0;
		}
		queue<vector<int>> q;
		q.push({dn, dm, 0});
		mag[dn][dm] = 1;
		while (!q.empty()) {
			vector<int> tmp = q.front();
			q.pop();
			int x = tmp[0];
			int y = tmp[1];
			int val = tmp[2];
			if (mat[x][y] == 1) {
				ans = val;
				break;
			}
			for (int i = max(0, x - 2); i <= min(n - 1, x + 2); i++) {
				for (int j = max(0, y - 2); j <= min(m - 1, y + 2); j++) {
					if (arr[i][j] == '.' && mag[i][j] == 0) {
						mag[i][j] = val + 1;
						q.push({i, j, mag[i][j]});
					}
				}
			}

		}
		cout << ans << "\n";
	}
	return 0;
}