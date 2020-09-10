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
		int n;
		cin >> n;
		ll arr[n];
		ll mx = 0;
		for (ll &i : arr) cin >> i;
		int el1 = -1, el2 = -1;
		int idx[n] = {0};
		idx[0] = 1;
		sort(arr, arr + n, greater<ll>());
		cout << arr[0] << " ";
		mx = arr[0];
		ll gd = 0, ele = -1;
		while (true) {
			ele = -1;
			for (int i = 0; i < n; i++) {
				if (idx[i] == 0) {
					ll gd1 = __gcd(mx, arr[i]);
					if (gd1 >= gd) {
						gd = gd1;
						ele = i;
					}
				}
			}
			if (ele == -1 || gd == 1) break;
			else {
				cout << arr[ele] << " ";
				idx[ele] = 1;
				mx = gd;
				gd = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			if (idx[i] == 0) cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}