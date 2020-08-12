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
ll fact[1000001];
int main(void)
{
	FIO
	int t = 1;
	while (t--)
	{
		int n;
		cin >> n;
		fact[0] = 1;
		for (int i = 1; i <= 1000000; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
		}
		ll ans = 0;
		ans = (fact[n] + mod - power(2, n - 1) % mod) % mod;
		cout << ans << '\n';
	}
	return 0;
}