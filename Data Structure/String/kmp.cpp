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
vector<int> cal_pref(string s) {
	int n = sz(s);
	vector<int> pref(n);
	pref[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = pref[i - 1];
		while (j > 0 && s[j] != s[i]) j = pref[j - 1];
		if (s[i] == s[j]) j++;
		pref[i] = j;
	}
	return pref;
}
int main(void)
{
	FIO
	int t = 1;
	while (t--)
	{
		string s, t;
		cin >> s >> t;
		vector<int> pref = cal_pref(s);
		int i = 0, j = 0;
		while (i < sz(t)) {
			if (s[j] == t[i]) {
				i++, j++;
			}
			else {
				if (j != 0) j = pref[j - 1];
				else i++;
			}
			if (j == sz(s)) {
				cout << "match at " << i - j << '\n';
				j = pref[j - 1];
			}
		}
	}
	return 0;
}