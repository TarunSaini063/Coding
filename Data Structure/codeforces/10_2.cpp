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
		ll n, k, x;
		cin >> n >> k;
		vector<ll> arr(n);
		for (auto &i : arr) cin >> i;
		ll mx = *max_element(all(arr));
		ll mn = *min_element(all(arr));
		if (mx == mn) {
			for (int i = 0; i < n; i++) cout << "0 ";
			cout << "\n";
			continue;
		}
		for (auto &i : arr) i = mx - i;
		k--;
		if (k % 2 == 1) {
			mx = *max_element(all(arr));
			for (auto i : arr) cout << mx - i << " ";
		}
		else {
			for (auto i : arr) cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}