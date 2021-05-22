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
ll fact[1001];
ll ncr(int n, int r) {
	return (fact[n] * (invmod(fact[r]) * invmod(fact[n - r] % mod) % mod)) % mod;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	fact[1] = 1;
	fact[0] = 0;
	for (ll i = 2; i <= 1000; i++) fact[i] = (i * fact[i - 1] % mod) % mod;
	while (t--)
	{
		ll n, x, pos;
		cin >> n >> x >> pos;
		ll ans = 1; // (fact[pos] * fact[n - pos - 1]) % mod;
		cout << ncr(n, pos) << "\n";
		// ans = (ans % ncr(n, pos)) % mod;
		// cout << ans << "\n";
	}
	return 0;
}