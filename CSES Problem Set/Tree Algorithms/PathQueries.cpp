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
const int mxn = 2e5 + 1;
vector<int> adj[mxn];
ll *ft, in[mxn], out[mxn], d = 1, n, arr[mxn];
void dfs(int id, int p) {
	in[id] = d++;
	for (int i : adj[id]) {
		if (i != p) {
			dfs(i, id);
		}
	}
	out[id] = d;
}
void upd(int i, int x) {
	for (++i; i <= d + 1; i += i & -i) {
		ft[i] += x;
	}
}
ll qry(int id) {
	ll sum = 0;
	for (++id; id > 0; id -= id & -id) {
		sum += ft[id];
	}
	return sum;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, -1);
		ft = new ll[d + 10];
		for (int i = 1; i <= n; i++) upd(in[i], arr[i]), upd(out[i], -arr[i]);
		while (q--) {
			int a;
			cin >> a;
			if (a == 1) {
				int s, x;
				cin >> s >> x;
				upd(in[s], x - arr[s]);
				upd(out[s], arr[s] - x);
				arr[s] = x;
			}
			else {
				cin >> a;
				cout << qry(in[a]) << "\n";
			}
		}

	}
	return 0;
}