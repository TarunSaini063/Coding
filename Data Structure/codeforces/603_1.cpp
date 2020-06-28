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
		ll arr[3];
		for (auto &i : arr)cin >> i;
		sort(arr, arr + 3);
		ll dif = arr[2] - arr[1];
		ll ans = min(dif, arr[0]);
		arr[2] -= min(dif, arr[0]);
		arr[0] -= min(arr[0], dif);
		ans += arr[0];
		arr[1] -= arr[0] / 2;
		arr[2] -= (arr[0] + 1) / 2;
		ans += min(arr[1], arr[2]);
		cout << ans << '\n';

	}
	return 0;
}