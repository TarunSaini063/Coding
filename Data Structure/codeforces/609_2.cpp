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
	ll n, m, x;
	cin >> n >> m;
	vector<ll> v1, v2;
	for (ll i = 0; i < n; i++) {
		cin >> x;
		v1.pb(x);
	}
	for (ll i = 0; i < n; i++) {
		cin >> x;
		v2.pb(x);
	}
	sort(all(v1));
	sort(all(v2));
	ll ans = 1e18;
	for (ll i = 0; i < n; i++) {
		ll dif = (v2[0] - v1[i] + m) % m;
		int fl = 0;
		for (ll j = 0; j < n; j++) {
			if ((v1[(i + j) % n] + dif) % m != v2[j]) {
				fl = 1;
				break;
			}
		}
		if (fl == 0) {
			ans = min(ans, dif);
		}
	}
	cout << ans << "\n";
	return 0;
}