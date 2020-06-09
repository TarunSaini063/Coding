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
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		map<ll, ll>mp;
		mp[1] = 1;
		for (ll i = 2; i <= n; i *= 2)
		{
			mp[i] = 2 * mp[i / 2] + 1;
		}
		ll ans = 0, i = 0;
		while (n > 0)
		{
			if (n & 1)
			{
				ans += mp[pow(2, i)];
			}
			i++;
			n >>= 1;
		}
		cout << ans << '\n';
	}
	return 0;
}