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
ll dis[mxn];
vector<ar<ll, 2>> adj[mxn + 1];
void dfs(int id) {
	set<ar<ll, 2>> st;
	memset(dis, 0x3f, sizeof(dis));
	dis[id] = 0;
	st.insert({0, id});
	while (!st.empty()) {
		int u = (*st.begin())[1];
		st.erase(st.begin());
		for (ar<ll, 2> it : adj[u]) {
			int to = it[1];
			ll len = it[0];
			if (dis[to] > dis[u] + len) {
				st.erase({dis[to], to});
				dis[to] = dis[u] + len;
				st.insert({dis[to], to});
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
		int  n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].pb({c, b});
		}
		dfs(1);
		for (int i = 1; i <= n; i++) cout << dis[i] << " ";
	}
	return 0;
}