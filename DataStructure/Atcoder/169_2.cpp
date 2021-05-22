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
		int n;
		cin >> n;
		ll arr[n], mul = 1e18, z = 1;
		for (auto &i : arr) {
			cin >> i;
			if (i == 0) {
				cout << 0 << "\n";
				return 0;
			}
		}
		for (auto i : arr) {
			if (i <= mul / z) {
				z *= i;
			}
			else {
				z = -1;
				break;
			}
		}
		cout << z << "\n";
	}
	return 0;
}