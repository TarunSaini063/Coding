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
int bin(ll pref[], ll val, int n) {

	int l = 0, h = n - 1, ans = -1;
	while (l <= h) {
		int md = l + (h - l) / 2;
		if (pref[md] > val) {
			h = md - 1;
		} else {
			ans = md;
			l = md + 1;
		}
	}
	return ans + 1;

}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, s;
		cin >> n >> s;
		int arr[n];
		for (auto &i : arr)cin >> i;
		ll pref[n], x = 0;
		pref[0] = arr[0];
		for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i];
		int ans = 0, mx = 0;
		for (int i = 0; i <= n; i++) {
			if (i > 1 && pref[i - 2] >= s) break;
			int id = bin(pref, s + x, n);
			if (mx < id) {
				mx = id;
				ans = i;
			}
			if (i == n ) break;
			x = arr[i];
		}
		cout << ans << "\n";
	}
	return 0;
}