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
const int mxn = 510;
int dp[mxn][mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> dp[i][j];
		}
		int x[n];
		ll ans[n];
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			x[i]--;
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					dp[j][k] = min(dp[j][k], dp[j][x[i]] + dp[x[i]][k]);
				}
			}
			for (int j = i; j < n; j++) {
				for (int k = i; k < n; k++)
					ans[i] += dp[x[j]][x[k]];
			}
		}
		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}