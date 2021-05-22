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
ll s, ans = 0, fact[2010];
ll ncr(int n, int r) {
	ll ans = fact[n];
	ll dev = (invmod(fact[n - r]) * fact[r]) % mod;
	ans = (ans * dev) % mod;
	return ans;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> s;
		fact[0] = 1;
		for (int i = 1; i <= s; i++) fact[i] = (fact[i - 1] * i) % mod;
		for (int i = 1; i <= s; i++)
			ans = (ans + ncr(s - 1, i - 1)) % mod;
		cout << ans << "\n";
	}
	return 0;
}