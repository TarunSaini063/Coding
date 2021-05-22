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
	ll t, k, n = 1e5 + 10;
	cin >> t >> k;
	ll dp[n];
	for (int i = 0; i < k; i++) dp[i] = 1;
	for (int i = k; i < n; i++) {
		dp[i] = (dp[i - 1] + dp[i - k]) % mod;
	}
	for (int i = 1; i < n; i++) dp[i] = (dp[i] + dp[i - 1]) % mod;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		cout << (dp[b] - dp[a - 1] + mod) % mod << "\n";
	}
	return 0;
}