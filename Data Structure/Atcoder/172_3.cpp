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
		ll n, m, k;
		cin >> n >> m >> k;
		ll a[n + 1], b[m + 1];
		a[0] = b[0] = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) cin >> b[i];
		for (int i = 0; i < n; i++) a[i + 1] += a[i];
		for (int i = 0; i < m; i++) b[i + 1] += b[i];
		int ans = 0, j = m;
		for (int i = 0; i <= n; i++) {
			if (a[i] > k) break;
			while (j >= 0 && b[j] > k - a[i]) j--;
			ans = max(ans, i + j);
		}
		cout << ans << "\n";
	}
	return 0;
}