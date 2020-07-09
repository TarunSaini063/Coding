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
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--) {
		ll a, b, c, d , e, f;
		cin >> a >> b >> c >> d >> e >> f;
		ll ans = 0;
		if (e > f) {
			ans += e * min(a, d);
			d -= min(a, d);
			ans += f * min({b, c, d});
		}
		else {
			ans += f * min({b, c, d});
			d -= min({b, c, d});
			ans += e * min(a, d);
		}
		cout << ans << "\n";
	}
	return 0;
}