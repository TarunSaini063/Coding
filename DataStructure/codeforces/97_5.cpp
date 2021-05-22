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
const int mxn = 5e5 + 2;
int arr[mxn], brr[mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int arr[n + 1];
		for (int i = 1; i <= n; i++) cin >> arr[i];
		brr[0] = 1;
		for (int i = 1; i <= k; i++) cin >> brr[i];
		brr[k + 1] = n;
		k += 2;
		int fl = 1;
		for (int i = 0; i < k - 1; i++) {
			if (arr[brr[i + 1]] <= arr[brr[i]] || arr[brr[i + 1]] - arr[brr[i]] < brr[i + 1] - brr[i] ) {
				fl = 0;
				break;
			}
		}
		if (!fl) cout << "-1\n";
		else {
			int ans = 0;
			for (int i = 0; i < k - 1; i++) {
				int start = brr[i];
				int end = brr[i + 1];
				int dp[2][end - start + 2] = {0};
				for (int j = start + 1; j < end; j++) {
					if (arr[j] > arr[j - 1]) {
						dp[0][j - start + 1] = dp[0][j - start];
					}
					dp[1][j - start + 1] = 1 + dp[0][j - start];
				}
				ans += min(dp[0][end - start + 1], dp[1][end - start + 1]);
				for (int i = 0; i < end - start + 1; i++) cout << dp[0][i] << " ";
				cout << "\n";
				for (int i = 0; i < end - start + 1; i++) cout << dp[1][i] << " ";
				cout << "\n";

			}
			cout << ans << "\n";
		}

	}
	return 0;
}