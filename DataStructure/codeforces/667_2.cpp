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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		ll ans = 1e18 + 10, q = 2;
		while (q--) {
			swap(a, b);
			swap(x, y);
			ll ta = a, tn = n, tb = b;
			ll dif = max(0ll, a - x);
			ta -= min(dif, tn);
			tn -= min(dif, tn);
			dif = max(0ll, b - y);
			tb -= min(dif, tn);
			ans = min(ans, ta * tb);
		}
		cout << ans << "\n";
	}
	return 0;
}