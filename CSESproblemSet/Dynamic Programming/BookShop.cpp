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
		int n, x;
		cin >> n >> x;
		int price[n + 1] = {0}, page[n + 1] = {0};
		for (int i = 0; i < n; i++) cin >> price[i + 1];
		for (int i = 0; i < n; i++) cin >> page[i + 1];
		int dp[n + 1][x + 1];
		for (int i = 0; i <= n; i++) dp[i][0] = 0;
		for (int i = 0; i <= x; i++) dp[0][i] = 0;
		for (int b = 1; b <= n; b++) {
			for (int pr = 1; pr <= x; pr++) {
				dp[b][pr] = dp[b - 1][pr];
				if (price[b] <= pr) {
					dp[b][pr] = max(page[b] + dp[b - 1][pr - price[b]], dp[b][pr]);
				}
			}
		}
		cout << dp[n][x] << '\n';
	}
	return 0;
}