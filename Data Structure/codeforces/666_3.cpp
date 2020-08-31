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
		ll n;
		cin >> n;
		ll arr[n];
		for (ll &i : arr) cin >> i;
		int len = n;
		if (n != 1) {
			cout << 1 << " " << len - 1 << "\n";
			for (int i = 0; i < len - 1; i++) {
				cout << (len - 1)*(arr[i] % n) << " ";
				arr[i] += ((len - 1) * (arr[i] % n));
			}
		} else {
			cout << 1 << " " << 1 << "\n";
			cout << 0;
		}
		cout << "\n";
		cout << n << " " << n << "\n";
		cout << -(arr[n - 1]) % (len) << "\n";
		arr[n - 1] += (-(arr[n - 1] % (len)));
		cout << 1 << " " << n << "\n";
		for (int i = 0; i < n; i++) {
			cout << -arr[i] << " ";
		}
	}
	return 0;
}