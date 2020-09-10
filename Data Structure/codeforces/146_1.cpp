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
		ll n, ans;
		cin >> n;
		if (n <= 2) {
			cout << n << '\n';
			return 0;
		}
		if (n == 3) {
			cout << 6 << '\n';
			return 0;
		}
		if (n % 2 == 1) {
			ans = n * (n - 1) * (n - 2);
		}
		else if (n % 3 == 0) ans = (n - 1) * (n - 2) * (n - 3);
		else ans = n * (n - 1) * (n - 3);
		cout << ans << "\n";
	}
	return 0;
}