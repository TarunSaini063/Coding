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
const int mxn = 1e5 + 10;
int height[mxn];
vector<int> tree[mxn];
void dfs(int id, int p, int h) {
	height[id] = h;
	for (int i : tree[id]) {
		if (i != p) {
			dfs(i, id, h + 1);
		}
	}
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, n, da, db, u, v;
		cin >> n >> a >> b >> da >> db;
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			tree[u].pb(v);
			tree[v].pb(u);
		}
		dfs(b, 0, 0);
		int mxid = max_element(height, height + n + 1) - height;
		int disa = height[a];
		dfs(mxid, 0, 0);
		int dia = *max_element(height, height + n + 1);
		if (disa > da && dia > 2 * da && db > 2 * da) {
			cout << "Bob\n";
		}
		else cout << "Alice\n";
		for (int i = 0; i <= n; i++) {
			tree[i].clear();
			height[i] = 0;
		}
	}
	return 0;
}