#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 100000000
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
		ll n1, n2, k1, k2, ans = 0;
		cin >> n1 >> n2 >> k1 >> k2;
		ll dp1[n1 + 1][n2 + 1];
		ll dp2[n1 + 1][n2 + 1];
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		dp1[0][0] = dp2[0][0] = 1;
		for (ll i = 0; i <= n1; i++) {
			for (ll j = 0; j <= n2; j++) {
				for (ll k = 1; k <= min(i, k1); k++) {
					dp1[i][j] += dp2[i - k][j];
					dp1[i][j] %= mod;
				}
				for (ll k = 1; k <= min(j, k2); k++) {
					dp2[i][j] += dp1[i][j - k];
					dp2[i][j] %= mod;
				}
			}
		}
		cout << (dp1[n1][n2] + dp2[n1][n2]) % mod << "\n";
	}
	return 0;
}