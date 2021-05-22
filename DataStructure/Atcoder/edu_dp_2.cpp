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
		int n, k;
		cin >> n >> k;
		ll arr[n];
		for (auto &i : arr) cin >> i;
		k = min(n, k);
		ll dp[n];
		dp[0] = 0;
		dp[1] = abs(arr[0] - arr[1]);
		// cout << dp[0] << " " << dp[1] << " ";
		for (int i = 2; i < n; i++) {
			dp[i] = 1e18;
			for (int j = max(0, i - k); j < i; j++) {
				dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
			}
			// cout << dp[i] << " ";
		}
		// cout << "\n";
		cout << dp[n - 1] << "\n";
	}
	return 0;
}