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
	int t = 30;
	// n=
	ll arr[t + 1], n;
	arr[1] = 1;
	arr[2] = 6;
	for (ll i = 3; i <= t; i++) {
		arr[i] = 2 * arr[i - 1] + (1ll << (i - 1)) * (1ll << (i - 1));
	}
	for (int i = 2; i <= t; i++)  arr[i] += arr[i - 1];
	cin >> t;
	while (t--)
	{
		cin >> n;
		ll mx = 0, ans = 0;
		for (int i = 1; i <= 30; i++) {
			if (arr[i] <= n) {
				ans = i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}