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
	// cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> mn(n), mx(n);
		for (int i = 0; i < n; i++) {
			cin >> mn[i] >> mx[i];
		}
		auto h = [](int n, vector<ll> arr)-> ll {
			sort(all(arr));
			if (n & 1) return arr[n / 2];
			return arr[n / 2] + arr[n / 2 - 1];
		};
		ll mnn = h(n, mn);
		ll mxn = h(n, mx);
		cout << mxn - mnn + 1 << '\n';
	}
	return 0;
}