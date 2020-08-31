#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define get cin
#define out cout
#define ss second
#define se(x) (int)x.size()
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
		string s;
		get >> s;
		int n, len = se(s);
		get >> n;
		string ans(len, '1');
		for (int i = 0; i < len; i++) {
			if (s[i] == '0') {
				if (i + n < len ) {
					ans[i + n] = '0';
				}
				if (i - n >= 0) {
					ans[i - n] = '0';
				}
			}
		}
		for (int i = 0; i < len; i++) {
			if (s[i] == '1') {
				int fl = 0;
				if (i + n < len && ans[i + n] == '1') {
					fl = 1;
				}
				if (i - n >= 0 && ans[i - n] == '1') {
					fl = 1;
				}
				if (fl == 0) {
					ans = "-1";
					break;
				}
			}
		}
		out << ans << "\n";

	}
	return 0;
}