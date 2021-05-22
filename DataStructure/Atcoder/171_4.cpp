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
int main(void)
{
	FIO
	ll n, x, q, y;
	cin >> n;
	ll arr[100002] = {0};
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		cin >> x;
		arr[x]++;
		ans += x;
	}
	cin >> q;
	while (q--)
	{
		cin >> x >> y;
		ans += y * arr[x];
		ans -= arr[x] * x;
		arr[y] += arr[x];
		arr[x] = 0;
		cout << ans << '\n';
	}
	return 0;
}