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
	// cin >> t;
	while (t--)
	{
		ll n, x;
		cin >> n;
		map<ll, ll> freq;
		ll mx = INT_MIN;
		for (ll i = 0; i < n; i++)
		{
			cin >> x;
			freq[x]++;
			mx = max(mx, x);
		}
		ll dp[mx + 1];
		dp[0] = 0;
		dp[1] = freq[1];
		for (ll i = 2; i <= mx; i++)
		{
			dp[i] = max(dp[i - 2] + (freq[i] * i), dp[i - 1]);
		}
		cout << dp[mx];
	}
	return 0;
}