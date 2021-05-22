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
int n, mn = 1e9, len, price[9];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n;
		for (int &i : price) cin >> i, mn = min(mn, i);
		len = n / mn;
		if (len == 0) {
			cout << "-1\n";
			return 0;
		}
		while (len--) {
			for (int i = 8; i >= 0; i--) {
				if (n >= price[i] && (n - price[i]) / mn == len) {
					cout << i + 1;
					n -= price[i];
					break;
				}
			}
		}
	}
	return 0;
}