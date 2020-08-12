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
ll fact[10100];
ll ncr(ll n, ll r) {
	return ((fact[n] * invmod(fact[n - r])) % mod * invmod(fact[r]) % mod) % mod;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	fact[0] = 1;
	for (ll i = 1; i < 10100; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll ans = ncr(n + 2 * m - 1, 2 * m) % mod;
		cout << ans << '\n';
	}
	return 0;
}