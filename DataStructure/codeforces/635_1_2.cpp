#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
bool cmp(const pair<ll, pair<int, int>> a, const pair<ll, pair<int, int>> b)
{
	return a.ff <= b.ff;
}
int main(void)
{
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt", "r", stdin);
// 	freopen("output1.txt", "w", stdout);
// #endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int nr, ng, nb;
		cin >> nr >> ng >> nb;
		vector<ll> r(nr), g(ng), b(nb);
		for (auto &j : r) cin >> j;
		for (auto &j : g) cin >> j;
		for (auto &j : b) cin >> j;
		sort(all(r)); sort(all(g)); sort(all(b));
		int i = 0, j = 0, k = 0;
		ll x, y, z, ans = 1e18 ;
		x = r[0], y = g[0], z = b[0];
		// ans = abs(x - y) * abs(x - y) + abs(y - z) * abs(y - z) + abs(x - z) * abs(x - z);
		while (true)
		{
			vector<pair<ll, pair<int, int>>> v;
			v.pb(mk(x, mk(nr, i)));
			v.pb(mk(y, mk(ng, j)));
			v.pb(mk(z, mk(nb, k)));
			sort(all(v), cmp);
			if (v[0].ss.ss < v[0].ss.ff)
			{
				x = r[i++];
				cout << "x " << x << "\n";
			}
			else if (v[1].ss.ss < v[1].ss.ff)
			{
				y = g[j++];
				cout << "y " << y << "\n";
			}
			else if (v[2].ss.ss < v[2].ss.ff)
			{
				z = b[k++];
				cout << "x " << x << "\n";
			}
			else break;
			if (x != y && y != z && z != x)
				ans = min(ans, abs(x - y) * abs(x - y) + abs(y - z) * abs(y - z) + abs(x - z) * abs(x - z));
			cout << i << " " << j << " " << k << "\n";
		}
		cout << ans << "\n";

	}
	return 0;
}