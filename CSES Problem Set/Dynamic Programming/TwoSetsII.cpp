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
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int sum = n * (n + 1) / 2;
		if (sum % 2) {
			cout << "0\n";
			return 0;
		}
		sum /= 2;
		int dp[2 * sum + 1] = {0};
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i * (i + 1) / 2; j >= i; j--) {
				dp[j] = (dp[j] + dp[j - i]) % mod;
			}
		}
		cout << (dp[sum]*invmod(2)) % mod;
	}
	return 0;
}