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
		ll n, sum = 0;
		cin >> n;
		ll arr[n];
		for (auto &i : arr) cin >> i, sum += i;
		if (sum % 3 != 0) {
			cout << "0\n";
		}
		else {
			ll dp[n], curr = 0;
			dp[0] = arr[0];
			sum /= 3;
			for (int i = 0; i < n; i++) {
				dp[i] = 0;
				curr += arr[i];
				if (curr == sum) dp[i] = 1;
			}
			for (int i = 1; i < n; i++) dp[i] += dp[i - 1];
			ll ans = 0;
			curr = 0;
			for (int i = n - 1; i >= 2; i--) {
				curr += arr[i];
				if (curr == sum) {
					ans += dp[i - 2];
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
