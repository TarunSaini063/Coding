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
	int t;
	cin >> t;
	while (t--)
	{
		ll n, x;
		cin >> n;
		vector<ll> arr, ans;
		for (int i = 0; i < n; i++) {
			cin >> x;
			arr.pb(x);
		}
		ll px = 1e18;
		arr.pb(px);
		ll mx = 0, curr = 0, res = 0, i = 0;
		while (i <= n) {
			if (arr[i] >= mx) {
				mx = arr[i++];
				ans.pb(0);
				continue;
			}
			ll j = i;
			curr = 0;
			while (j < n && arr[j] < mx) {
				ans.pb(mx - arr[j]);
				j++;
			}
			i = j;
		}
		i = 0;
		for (i = 0; i < n; i++) {
			if (ans[i + 1] - ans[i] > 0) res += ans[i + 1] - ans[i];
		}
		cout << res << "\n";
	}
	return 0;
}