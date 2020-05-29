#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 998244353
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}

const int mxn = 2e5;
ll fact[mxn];
ll ncr(int n, int r)
{
	return ((fact[n] * invmod(fact[n - r])) % mod * (invmod(fact[r]) % mod)) % mod;
}
int main(void)
{
	FIO

	fact[0] = 1;
	for (int i = 1; i <= mxn; i++) fact[i] = (fact[i - 1] * i) % mod;
	int n, m;
	cin >> n >> m;
	ll ans = ((ncr(m, n - 1) * (n - 2)) % mod * power(2, n - 3) % mod) % mod;
	cout << ans << '\n';
	return 0;
}