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
string s;
bool pal(int x, int y) {
	while (x < y) {
		if (s[x] != s[y]) return false;
		x++, y--;
	}
	return true;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{

		cin >> s;
		vector<string> ans;
		int n = sz(s);
		vector<int> left(n, 0), right(n, 0);
		for (int i = 0; i < n; i++) {
			if (pal(0, i)) {
				left[i] = 1;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (pal(i, n - 1)) {
				right[i] = 1;
			}
		}
		int fl = 0;
		for (int i = 0; i < n - 1; i++) {
			if (left[i] == 0) continue;
			for (int j = i + 1; j < n - 1; j++) {
				if (pal(i + 1, j) && right[j + 1]) {
					ans.pb(s.substr(0, i + 1));
					ans.pb(s.substr(i + 1, j - i));
					ans.pb(s.substr(j + 1));
					fl = 1;
					break;
				}
				if (fl == 1) break;
			}
			if (fl) break;
		}
		if (fl) {
			for (auto i : ans) cout << i << "\n";
		}
		else cout << "impossible\n";
	}
	return 0;
}