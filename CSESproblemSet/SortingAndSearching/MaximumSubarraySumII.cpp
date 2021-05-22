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
		ll n, a, b, ans = -1e18;
		cin >> n >> a >> b;
		ll arr[n + 1] = {0};
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] += arr[i - 1];
		}
		set<ar<ll, 2>> st;
		for (int i = 0; i <= n; i++) {
			if (i >= a) st.insert({arr[i - a ], i - a});
			if (sz(st))
				ans = max(ans, arr[i] - (*st.begin())[0]);
			if (i >= b) st.erase({arr[i - b], i - b});
		}
		cout << ans << "\n";
	}
	return 0;
}