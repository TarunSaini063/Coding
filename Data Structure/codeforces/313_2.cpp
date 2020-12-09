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
const int mxn = 2e6 + 1;
ll pw[mxn], hasha[mxn], hashb[mxn], pr = 29;
string a, b;
bool match(int as, int ae, int bs, int be) {
	if (as == ae) return a[as] == b[bs];
	ll A = (hasha[ae + 1] - hasha[as] + mod) % mod;
	A = (A * pw[as]) % mod;
	ll B = (hashb[be + 1] - hashb[bs] + mod) % mod;
	B = (B * pw[bs]) % mod;
	if (A == B) return true;
	int mida = (as + ae) / 2;
	int midb = (bs + be) / 2;
	return (match(as, mida, bs, midb) && match(mida + 1, ae, midb + 1, be)) ||
	       (match(as, mida, midb + 1, be) && match(mida + 1, ae, bs, midb));
}
string match(string s) {
	int n = sz(s);
	if (n & 1) return s;
	string l = match(s.substr(0, n / 2));
	string r = match(s.substr(n / 2));
	return min(l + r, r + l);
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int n = sz(a);
		pw[0] = 1;
		for (int i = 1; i <= n; i++) {
			pw[i] = (pw[i - 1] * pr) % mod;
		}
		for (int i = 1; i <= n; i++) {
			hasha[i] = (hasha[i - 1] + (a[i - 1] - 'a') * pw[i - 1]) % mod;
			hashb[i] = (hashb[i - 1] + (b[i - 1] - 'a') * pw[i - 1]) % mod;
		}
		if (match(a) == match(b)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}