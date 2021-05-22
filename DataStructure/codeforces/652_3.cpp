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
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<ll> a(n), w(k);
		for (auto &i : a) cin >> i;
		for (auto &i : w)cin >> i;
		sort(all(a));
		sort(all(w));
		int i = n - k - 1, j = n - 1;
		ll ans = 0;
		for (int l = 0; l < k; l++) {
			if (w[l] == 1) ans += 2 * a[j--];
			else {
				ans += a[j--];
				w[l]--;
				while (w[l] > 1) {
					i--;
					w[l]--;
				}
				ans += a[i--];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}