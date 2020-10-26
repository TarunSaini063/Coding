#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 998244353
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 3e5 + 1;
ll fact[mxn];
ll ncr(int n, int r) {
	if (n < r) return 0;
	return (fact[n] * invmod(fact[r]) % mod * invmod(fact[n - r]) % mod) % mod;
}
int main(void)
{
	FIO
	int t = 1;
	fact[0] = 1;
	for (ll i = 1; i < mxn; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	// cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<ar<ll, 2>> arr(n);
		for (auto &i : arr) {
			cin >> i[0] >> i[1];
		}
		sort(all(arr));
		multiset<ll> s;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && (*s.begin()) < arr[i][0]) s.erase(s.begin());
			ll N = sz(s);
			ans = (ans + ncr(N, k - 1)) % mod;
			s.insert(arr[i][1]);
		}
		cout << ans << "\n";
	}
	return 0;
}