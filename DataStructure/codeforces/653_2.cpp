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
	while (t--) {
		ll n;
		cin >> n;
		int tw = 0, th = 0;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		while (n % 2 == 0) {
			n /= 2;
			tw++;
		}
		while (n % 3 == 0) {
			n /= 3;
			th++;
		}
		if (n != 1 || th == 0 || tw > th) {
			cout << "-1\n";
		}
		else {
			cout << 2 * th - tw << "\n";
		}
	}
	return 0;
}