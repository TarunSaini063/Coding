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
		vector<ll>arr(n);
		for (ll &i : arr)cin >> i;
		sort(all(arr));
		ll ans = arr[0] * arr[1] * arr[2] * arr[3] * arr[4];
		for (int i = 0; i < 5; i++)
		{
			ll curr = 1;
			for (int j = 0; j < i; j++)
				curr *= arr[j];

			for (int j = n - 1; j >= n - 5 + i; j--)
				curr *= arr[j];

			ans = max(ans, curr);
		}
		cout << ans << "\n";
	}
	return 0;
}