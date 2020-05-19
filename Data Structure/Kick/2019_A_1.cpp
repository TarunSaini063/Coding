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
const int mxn = 1e5;
int arr[mxn];
void solve(void)
{
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	ll pref[n + 1];
	pref[0] = 0;
	for (int i = 0; i < n; i++) pref[i + 1] = arr[i] + pref[i];
	ll mx = 1e18;
	for (int i = p - 1; i < n; i++)
	{
		ll sm = pref[i + 1] - pref[i - p + 1];
		sm = p * arr[i] - sm;
		mx = min(mx, sm);
	}
	cout << max(mx, 0 * 1ll) << "\n";
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