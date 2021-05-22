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
		ll n, m, k;
		cin >> n >> m >> k;
		ll arr[n], brr[m];
		for (int i = 0; i < n; i++) arr[i] = i + 1;
		for (int i = 0; i < m; i++) brr[i] = i + 1;
		ll l = 1, h = n * m, ans = 1;
		while (l <= h) {
			ll mid = (l + h) / 2, tot = 0, j = m - 1;
			for (int i = 0; i < n; i++) {
				while (j >= 0 && arr[i]*brr[j] > mid) {
					j--;
				}
				tot += (j + 1);
			}
			if (tot >= k) {
				ans = mid;
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}