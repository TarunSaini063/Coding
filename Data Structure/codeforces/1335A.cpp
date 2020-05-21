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
ll getAdd(ll x) {
	ll m1 = 10, m2 = 0;
	while (x > 0) {
		ll y = x % 10;
		x /= 10;
		m1 = min(m1, y);
		m2 = max(m2, y);
	}
	return m1 * m2;
}

int main()
{

	int t;
	scanf("%d", &t);
	while (t--) {
		ll x, k;
		scanf("%lld%lld", &x, &k);
		k--;
		while (k--) {
			ll y = getAdd(x);
			if (y == 0) break;
			x += y;
		}
		printf("%lld\n", x);
	}

	return 0;
}