#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
void solve(void)
{
	ll w, n;
	cin >> w >> n;
	ll arr[w];
	for (int i = 0; i < w; i++) cin >> arr[i];
	if (n == 1) {
		cout << "0\n";
		return;
	}
	sort(arr, arr + w, [&](ll x, ll y) {
		x = min(x, n - x);
		y = min(y, n - y);
		return x < y;
	});
	// cout << "\n";
	auto get = [&](ll dig) {
		ll ans = 0;
		for (ll i : arr) {
			ans += min(abs(dig - i), n - abs(dig - i));
		}
		return ans;
	};
	// for (ll i : arr) cout << i << " ";
	// cout << "\n";
	ll ans = 1e18;
	for (ll i = 1; i <= n; i++) ans = min(ans, get(i)); // << " ";
	// cout << "\n";
	// ll med = arr[w / 2];
	// ll ans = get(med);
	// if (med > 1) ans = min(ans, get(med - 1));
	// if (med < n) ans = min(ans, get(med + 1));
	cout << ans << '\n';
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}