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
const int mxn = 1e6 + 1;
int fl[mxn], len[mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int k = 0, n = sz(s);
		for (int i = 1; i < n; i++) {
			while (k && s[i] != s[k]) k = len[k - 1];
			if (s[i] == s[k])k++;
			if (i < n - 1) fl[k] = 1;
			len[i] = k;
		}
		k = len[n - 1], fl[0] = 1;
		while (k && !fl[k])k = len[k - 1];
		if (k) cout << s.substr(0, k) << '\n';
		else cout << "Just a legend\n";
		// for (int i = 0; i < n; i++) cout << fl[i] << " "; cout << "\n";
		// for (int i = 0; i < n; i++) cout << len[i] << " "; cout << "\n";
	}
	return 0;
}