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
ll fun(vector<ll> arr) {
	ll ans = 0, curr = 0;
	for (auto i : arr) {
		curr = max(curr + i, 0ll);
		ans = max(ans, curr);
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
		int n;
		cin >> n;
		vector<ll>arr(n), a1, a2;
		for (auto &i : arr)cin >> i;
		ll sm = 0;
		for (int i = 0; i < n; i += 2) sm += arr[i];
		for (int i = 0; i < n - 1; i += 2) {
			a1.pb(arr[i + 1] - arr[i]);
		}
		for (int i = 1; i < n - 1; i += 2) {
			a2.pb(arr[i] - arr[i + 1]);
		}
		cout << sm + max(fun(a1), fun(a2)) << "\n";
	}
	return 0;
}