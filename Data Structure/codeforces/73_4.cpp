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
const int mxn = 3e5 + 5;
ll dp[mxn][3], arr[mxn], brr[mxn], n;

int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i + 1] >> brr[i + 1];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 2; j++) {
				dp[i][j] = 1e18;
				for (int k = 0; k <= 2; k++) {
					if (arr[i] + j != arr[i - 1] + k) {
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * brr[i]);
					}
				}
			}
		}
		cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
	}
	return 0;
}