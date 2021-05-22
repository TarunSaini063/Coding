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
	int t;
	cin >> t;
	while (t--)
	{
		int p, f, cnts, cntw, s, w;
		cin >> p >> f >> cnts >> cntw >> s >> w;
		if (cnts > cntw) {
			swap(cntw, cnts);
			swap(s, w);
		}
		int ans = 0;
		for (int sword = 0; sword <= min(p / s, cnts); sword++) {
			int pax = min((p - sword * s) / w, cntw);
			int fax = min(cntw - pax, f / w);
			int fsw = min(cnts - sword, (f - fax * w) / s);
			ans = max(ans, sword + pax + fsw + fax);
			fsw = min(cnts - sword, f / s);
			fax = min(cntw - pax, (f - fsw * s) / w);
			ans = max(ans, sword + pax + fsw + fax);
		}
		cout << ans << '\n';
	}
	return 0;
}