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
vector<vector<ll>>dis;
ll n, m, l, a, b, c;
void solve() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
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
		cin >> n >> m >> l;
		dis.assign(n, vector<ll>(n, 1e17));
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			a--, b--;
			dis[a][b] = c;
			dis[b][a] = c;
		}
		solve();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) dis[i][j] = 0;
				else dis[i][j] = (dis[i][j] <= l) ? 1 : 1e18;
			}
		}
		solve();
		int q;
		cin >> q;
		while (q--) {
			cin >> a >> b;
			a--, b--;
			if (dis[a][b] < 1e18) cout << dis[a][b] - 1 << "\n";
			else cout << "-1\n";
		}
	}
	return 0;
}