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
	// cin>>t;
	while (t--)
	{
		int n, k;
		cin	>> n >> k;
		ll arr[n];
		for (ll &i : arr) cin >> i;
		multiset<ll> s;
		for (int i = 0; i < k; i++) {
			s.insert(arr[i]);
		}
		auto med = s.begin();
		ll tot = 0, right = 0, lcnt = 0, rcnt = 0, left = 0;
		for (int i = 0; i < (k - 1) / 2; i++) {
			left += (*med);
			lcnt++;
			med++;
		}
		for (int i = 0; i < k; i++) {

			right += arr[i];
			rcnt++;
		}
		tot = right;
		right = right - left - (*med);
		rcnt = rcnt - lcnt - 1;
		for (int i = k; i <= n; i++) {
			ll ans = (k - rcnt - 1) * (*med) - (tot - right - *med);
			ans += right - rcnt * (*med);
			cout << ans << ' ';
			if (i == n) break;
			tot += arr[i];
			s.insert(arr[i]);
			if (arr[i] < (*med)) {
				rcnt++;
				right += (*med);
				med--;
			}
			else {
				rcnt++;
				right += arr[i];
			}
			if (arr[i - k] <= (*med)) {
				rcnt--;
				med++;
				right -= (*med);
			}
			else {
				rcnt--;
				right -= arr[i - k];
			}
			tot -= arr[i - k];
			s.erase(s.lower_bound(arr[i - k]));
		}
	}
	return 0;
}