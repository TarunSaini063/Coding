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
		string s, h;
		ll x;
		cin >> x >> s;
		ll ans = s.size();
		for (int i = 0; i < x; i++) {
			if (s[i] == '1')continue;
			if (s.size() < x) {
				h = s.substr(i + 1);
				for (int j = 0; j < s[i] - '1'; j++) s += h;
			}
			ans = (ans + (ans - i - 1) * (s[i] - '0' - 1) + mod) % mod;
		}
		cout << ans % mod << "\n";
	}
	return 0;
}