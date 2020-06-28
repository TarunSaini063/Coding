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
		int n;
		ld g, a, b, ans1 = 0, ans2 = 0;
		cin >> n;
		vector<ld> arr;
		for (int i = 0; i < n; i++) {
			cin >> g >> a >> b;
			ans1 += g * ((1.0 * b) / (a + b));
			ans2 += g * ((1.0 * a) / (a + b));
		}
		cout << setprecision(6) << fixed << ans1 << " " << ans2 << "\n";
	}
	return 0;
}