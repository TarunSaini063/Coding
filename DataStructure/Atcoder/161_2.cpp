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
	// cin >> t;
	while (t--)
	{
		ll n, m, sm = 0, cnt = 0;
		cin >> n >> m;
		ll arr[n];
		for (auto &i : arr) cin >> i, sm += i;
		for (auto i : arr) {
			if (sm <= 4 * i * m) cnt++;
		}
		if (cnt >= m) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}