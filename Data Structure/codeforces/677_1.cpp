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
	vector<string> v;
	for (int i = 1; i <= 9; i++) {
		int j = i;
		while (j <= 10000) {
			string s = to_string(j);
			v.push_back(s);
			j = j * 10 + i;
		}
	}
	sort(all(v));
	while (t--)
	{
		string s;
		cin >> s;
		int ans = 0;
		for (auto i : v) {
			ans += sz(i);
			if (s == i) break;
		}
		cout << ans << "\n";
	}
	return 0;
}