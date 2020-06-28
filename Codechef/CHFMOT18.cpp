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
	while (t--) {
		ll s, n;
		cin >> s >> n;
		ll mx = n;
		if (n % 2 == 1) mx--;
		if (s <= mx) {
			if (s % 2 == 0 || s == 1) cout << "1\n";
			else cout << "2\n";
		}
		else {
			ll ans = s / mx;
			s -= ans * mx;
			if (s != 0) {
				if (s % 2 == 0 || s == 1) ans += 1;
				else ans += 2;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}