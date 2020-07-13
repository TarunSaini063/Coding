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
vector<ll> pw;
ll comp_hash(string s)
{
	int p = 31;
	ll res = 0, pow = 1;
	for (auto i : s) {
		res = (res + pow * (i - 'a' + 1) % mod) % mod;
		pow = (p * pow) % mod;
	}
	return res;
}
vector<vector<string>> group_dublicate(vector<string> v) {
	vector<pair<ll, int>> arr(sz(v));
	for (int i = 0; i < sz(v); i++) {
		arr[i] = mk(comp_hash(v[i]), i);
	}
	sort(all(arr));
	vector<vector<string>> res;
	for (int i = 0; i < sz(arr); i++) {
		if (i == 0 || arr[i - 1].ff != arr[i].ff)
			res.pb();
		res.back().pb(v[arr[i].ss]);
	}
	return res;
}
int main(void)
{
	FIO
	int t = 1;
	// cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<string>s(n);
		for (auto &i : s)cin >> i;
		auto it = group_dublicate(s);
		for (auto i : it) {
			for (auto j : i) cout << j << " ";
			cout << '\n';
		}
	}
	return 0;
}