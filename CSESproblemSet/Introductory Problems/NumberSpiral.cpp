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
		ll x, y;
		cin >> y >> x;
		if (x > y) {
			if (x & 1) {
				x *= x;
				cout << x - y + 1 << '\n';
			}
			else {
				x = (x - 1) * (x - 1);
				cout << x + y  << "\n";
			}
		}
		else {
			if (y & 1 ^ 1) {
				y *= y;
				cout << y - x + 1 << "\n";
			}
			else {
				y = (y - 1) * (y - 1);
				cout << y + x  << '\n';
			}
		}
	}
	return 0;
}