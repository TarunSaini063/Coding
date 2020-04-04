#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define all(x) x.begin(), x.end()
ll power(ll a, ll b)
{
	ll res = 1;
	a = a % mod;
	while (b)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}
ll invmod(ll a) { return power(a, mod - 2); }
int main(void)
{
	FIO
		std::vector<ll>
			fact(1000001);
	fact[0] = 1;
	ll ans = 0;
	for (int i = 1; i < 1000001; i++)
		fact[i] = (fact[i - 1] * i) % mod;
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				ans = (ans + fact[i + j] * invmod(fact[i] * fact[j])) % mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
