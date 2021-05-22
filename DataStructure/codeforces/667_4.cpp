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
int get(ll x) {
	int ans = 0;
	while (x) {
		ans += (x % 10);
		x /= 10;
	}
	return ans;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll n, s, tmp, dig = 10;
		cin >> n >> s;
		tmp = n;
		while (get(tmp) > s) {
			tmp += dig - tmp % dig;
			dig *= 10;
		}
		cout << tmp - n << "\n";
	}
	return 0;
}