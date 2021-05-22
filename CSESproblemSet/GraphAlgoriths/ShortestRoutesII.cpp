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
const int mxn = 5e2 + 1;
vector<ar<ll, 2>> adj[mxn];
ll dis[mxn][mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m, q;
		cin >> n >> m >> q;
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 0; i < m; i++) {
			ll a, b, c;
			cin >> a >> b >> c;
			dis[a][b] = min(dis[a][b], c);
			dis[b][a] = min(dis[b][a], c);
		}
		for (int i = 1; i <= n; i++) dis[i][i] = 0;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		while (q--) {
			int a, b;
			cin	>> a >> b;
			if (dis[a][b] >= 1e18) cout << "-1\n";
			else cout << dis[a][b] << "\n";
		}
	}
	return 0;
}