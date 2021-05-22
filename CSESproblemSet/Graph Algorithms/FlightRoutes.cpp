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
const int mxn = 1e5 + 1;
vector<ar<ll, 2>>adj[mxn], adj2[mxn];
vector<ll>dis[mxn];
int n, m, k;
void dij(int id) {
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> s;
	s.push({0, id});
	while (!s.empty()) {
		ar<ll, 2> u = s.top();
		s.pop();
		if (dis[u[1]].size() >= k) continue;
		dis[u[1]].pb(u[0]);
		for (ar<ll, 2> tmp : adj[u[1]]) {
			int to = tmp[1];
			ll len = tmp[0];
			s.push({u[0] + len, to});
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
		cin >> n >> m >> k;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].pb({c, b});
		}
		dij(1);
		for (int i = 0; i < sz(dis[n]); i++) cout << dis[n][i] << " ";
	}
	return 0;
}