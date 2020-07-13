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
	// cin>>t;
	while (t--)
	{
		int n;
		cin	>> n;
		ll arr[n + 1], pref[n + 1] = {0}, suff[n + 1];
		for (int i = 1; i <= n; i++)cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			pref[i] = arr[i];
			if (i >= 2) pref[i] += pref[i - 2];
		}
		for (int i = n; i >= 1; i--) {
			suff[i] = arr[i];
			if (i <= n - 2) suff[i] += suff[i + 2];
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, pref[i - 1] + suff[i]);
		cout << ans << "\n";
	}
	return 0;
}