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
set<string> st;
void solve(int id, int n, string &s) {
	if (id == n) {
		st.insert(s);
		return;
	}
	for (int i = id; i < n; i++) {
		swap(s[i], s[id]);
		solve(id + 1, n, s);
		swap(s[i], s[id]);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		solve(0, sz(s), s);
		cout << sz(st) << "\n";
		for (auto i : st) cout << i << '\n';
	}
	return 0;
}