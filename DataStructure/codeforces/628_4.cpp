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
		ll u, v;
		cin >> u >> v;
		if (u > v || u - v & 1) cout << "-1\n";
		else if (u == 0 && v == 0) cout << "0\n";
		else if (!(u ^ v)) cout << "1\n" << u << '\n';
		else {
			ll diff = (v - u) / 2;
			if (u & diff) {
				cout << "3\n";
				cout << u << " " << diff << ' ' << diff << '\n';
			}
			else {
				cout << "2\n";
				cout << u + diff << " " << diff << '\n';
			}
		}
	}
	return 0;
}