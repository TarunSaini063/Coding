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
ll n, d;
bool solve(vector<ll> &arr, ld cool) {
	double t = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (t <= arr[i]) {
			t = arr[i] + cool;
		}
		else if (t > arr[i] + d) return false;
		else t += cool;
	}
	return true;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> d;
		vector<ll>c(n);
		for (ll &i : c) cin >> i;
		sort(all(c));
		ld mn = 0, mx = 1e18, ans = -1.0;
		while (mx - mn >= 0.000001) {
			ld mid = mn + (mx - mn) / 2.0;
			if (solve(c, mid)) {
				ans = mid;
				mn = mid;
			}
			else mx = mid;
		}
		cout << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}