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
		ll n, k;
		cin >> n >> k;
		if (n <= k) cout << 1 << "\n";
		else
		{
			ll ans = 0;
			for (ll i = 1; i * i <= n && i <= k; i++)
			{
				if (n % i == 0)
				{
					ans = max(ans, i);
					if (n / i <= k)
					{
						ans = max(ans, n / i);
					}
				}
				// cout << i << "\n";
			}
			cout << n / ans << "\n";
		}
	}
	return 0;
}