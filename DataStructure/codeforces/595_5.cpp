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
int a[mxn], b[mxn], c, n, dp[mxn][2];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> c;
		for (int i = 1; i < n; i++)cin >> a[i];
		for (int i = 1; i < n; i++) cin >> b[i];
		dp[0][0] = 0;
		dp[0][1] = c;
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
			dp[i][1] = min(dp[i - 1][0] + c + b[i], dp[i - 1][1] + b[i]);
		}
		for (int i = 0; i < n; i++) cout << min(dp[i][0], dp[i][1]) << " ";
		cout << '\n';
	}
	return 0;
}