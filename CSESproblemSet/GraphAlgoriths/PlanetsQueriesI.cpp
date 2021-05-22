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
const int mxn = 2e5 + 1;
int dp[30][mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			cin >> dp[0][i];
			dp[0][i]--;
		}
		for (int i = 1; i < 30; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = dp[i - 1][dp[i - 1][j]];
			}
		}
		while (q--) {
			int x, k;
			cin >> x >> k;
			x--;
			while (k > 0) {
				int d = log2(k);
				x = dp[d][x];
				k -= exp2(d);
			}
			cout << x + 1 << '\n';
		}
	}
	return 0;
}