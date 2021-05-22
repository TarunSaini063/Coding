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
	int t = 1;
	// cin >> t;
	while (t--)
	{
		ll n, k, tot, without, d;
		cin >> n >> k >> d;
		vector<ll> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++ ) {
				if (i >= j) {
					dp[i] = (dp[i - j] + dp[i]) % mod;
				}
			}
		}
		tot = dp[n];
		dp.assign(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < d; j++) {
				if (i >= j) dp[i] = (dp[i] + dp[i - j]) % mod;
			}
		}
		without = dp[n];
		cout << (tot - without + mod) % mod;
	}
	return 0;
}