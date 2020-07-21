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
	int t;
	cin >> t;
	while (t--)
	{
		ll l, r, m, fl = 0;
		cin >> l >> r >> m;
		ll mnn = m - (r - l);
		ll mnx = m + (r - l);
		for (ll i = l; i <= r && fl == 0; i++) {
			ll tmp = mnx / i * i;
			if (tmp >= mnn) {
				ll req, j;
				for (j = l; j <= r; j++) {
					req = tmp - m + j;
					if (req >= l && req <= r) break;
				}
				cout << i << ' ' << j << ' ' << req << '\n';
				fl = 1;
			}
		}

	}
	return 0;
}