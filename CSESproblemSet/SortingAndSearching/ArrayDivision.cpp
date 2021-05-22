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
		ll n, k;
		cin >> n >> k;
		ll arr[n], now = 0;
		for (auto &i : arr)cin >> i, now += i;
		auto solve = [&](ll sum) {
			ll curr = 0, tot = 1;
			for (int i = 0; i < n; i++) {
				curr += arr[i];
				if (curr  > sum) {
					tot++;
					i--;
					curr = 0;
				}

				if (tot > k || arr[i] > sum) return false;
			}
			return true;
		};
		ll l = *max_element(arr, arr + n), r = now, ans = -1;
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			if (solve(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}