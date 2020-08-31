#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define get cin
#define out cout
#define ss second
#define se(x) (int)x.size()
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
		ll n, ans = 0;
		get >> n;
		vector<ll>arr(n), l(n + 1, 0);
		for (ll &i : arr) get >> i;
		for (int i = 0; i < n; i++) {
			vector<ll> tmp(n + 1, 0);
			for (ll j = n - 1; j > i; j--) {
				ans += l[arr[j]] * tmp[arr[i]];
				tmp[arr[j]]++;
			}
			l[arr[i]]++;
		}
		out << ans << "\n";
	}
	return 0;
}