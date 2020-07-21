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
	// cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ld> dp(n + 1);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			ld pd;
			cin >> pd;
			for (int j = i + 1; j >= 0; j--) {
				dp[j] = (j == 0 ? 0 : dp[j - 1] * pd) + dp[j] * (1.0 - pd);
			}
		}
		ld ans = 0;
		for (int i = (n + 1) / 2; i <= n; i++) ans += dp[i];
		cout << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}