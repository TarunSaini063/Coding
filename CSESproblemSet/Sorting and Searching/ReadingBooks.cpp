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
		int n;
		cin >> n;
		ll arr[n], sum = 0;
		for (ll &i : arr)cin >> i, sum += i;
		sort(arr, arr + n);
		ll tot = 0;
		for (int i = 0; i < n - 1; i++) tot += arr[i];
		if (tot > arr[n - 1]) cout << sum;
		else cout << 2 * arr[n - 1];
	}
	return 0;
}