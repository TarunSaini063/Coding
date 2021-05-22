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
int m, n, a, b, mx = 1;
vector<int> size, par;
int root(int x) {
	if (x == par[x]) return x;
	return par[x] = root(par[x]);
}
void uni(int x, int y) {
	x = root(x);
	y = root(y);
	if (size[x] > size[y]) swap(x, y);
	par[x] = y;
	size[y] += size[x];
	mx = max(mx, size[y]);
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int com = n;
		for (int i = 0; i < n + 1; i++) size.pb(1), par.pb(i);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (root(a) != root(b)) {
				uni(a, b);
				com--;

			}
			cout << com << " " << mx << "\n";
		}
	}
	return 0;
}