#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
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
		ll a, b;
		cin >> a >> b;
		ll dif = b - a, ans = 0, pw = 1, len = 0;
		while (dif >= pw) {
			ans += pw;
			pw <<= 1;
			len++;
		}
		// cout << ans << " " << len << "\n";
		while (pw <= b) {
			if (((b >> len) ^ (a >> len)) & 1ll == 1ll) ans += pw;
			pw <<= 1;
			len++;
		}
		cout << ans << "\n";
	}
	return 0;
}