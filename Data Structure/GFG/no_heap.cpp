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
ll fact[105];
ll power(ll a, ll b) {
	a %= mod;
	ll ans = 1;
	while (b) {
		if (b & 1)ans = (a * ans) % mod;
		a = (a % mod * a % mod) % mod;
		b /= 2;
	}
	return ans % mod;
}

ll ncr(ll n, ll r) {
	if (n < r) return 0;
	return (fact[n] * (power(fact[n - r], mod - 2) % mod * power(fact[r], mod - 2) % mod) % mod) % mod;
}
vector<vector<ll>>dp;

ll solve(int n) {
	if (n <= 1) return 1;
	ll h = log2(n);
	ll tot_in_ht_h = pow(2, h + 1) - 1;
	ll tot_upto_ht_h_1 = pow(2, h) - 1;
	ll at_last_level = tot_in_ht_h - tot_upto_ht_h_1;
	ll in_left_level = at_last_level / 2;
	ll we_have_at_last_level = n - tot_upto_ht_h_1;
	ll left = we_have_at_last_level;
	if (we_have_at_last_level >= in_left_level) left = in_left_level;
	left += (tot_upto_ht_h_1 - 1) / 2;
	if (dp[left][n - left - 1] != -1) return dp[left][n - left - 1];
	ll ans = (ncr(n - 1, left) % mod * (solve(left) % mod * (solve(n - left - 1)) % mod) % mod) % mod;
	return dp[left][n - left - 1] = ans % mod;
}
int main(void)
{
	FIO
	fact[0] = 1;
	for (int i = 1; i <= 100; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		dp = vector<vector<ll>>(105, vector<ll>(105, -1));
		cin >> n;
		ll ans = solve(n);
		cout << ans << "\n";
	}
	return 0;
}